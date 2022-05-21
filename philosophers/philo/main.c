/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:54:28 by abouhmad          #+#    #+#             */
/*   Updated: 2022/05/21 14:41:29 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo(void *philo)
{
	t_philo	*p;

	p = (t_philo *) philo;
	if (p->np % 2 == 0)
		usleep(600);
	while (1)
	{
		if (gettime() - p->is_die >= p->d->die)
			return (0);
		pthread_mutex_lock(p->lfork);
		printf("L: %p ID: %zu\n", p->lfork, p->np);
		m_msg(p, "has take a fork");
		if (p->rfork == p->lfork)
			return (0);
		pthread_mutex_lock(p->rfork);
		printf("R: %p ID: %zu\n", p->rfork, p->np);
		m_msg(p, "has take a fork");
		p->is_die = gettime();
		m_msg(p, "is eating");
		if (p->p_neat > 0)
			p->p_neat--;
		ft_usp(p->d->eat * 1000);
		pthread_mutex_unlock(p->rfork);
		printf("Put R: %p ID: %zu\n", p->rfork, p->np);
		pthread_mutex_unlock(p->lfork);
		printf("Put L: %p ID: %zu\n", p->lfork, p->np);
		ft_is(p);
	}
	return (0);
}

int	check_neat(t_data *data, t_philo *p)
{
	size_t	i;
	size_t	neat;

	i = 0;
	neat = 0;
	if (data->neat > 0)
	{
		while (i < data->philo)
		{
			neat += p[i].p_neat;
			i++;
		}
		if (neat == 0)
		{
			pthread_mutex_lock(p->wr);
			printf("\033[1;32m\nAll Philos finished their meals\n\n");
			return (0);
		}
	}
	return (1);
}

int	check_dieing(t_data *data, t_philo *p)
{
	size_t	i;
	size_t	time;
	while (1)
	{
		i = 0;
		while (i < data->philo)
		{
			if (gettime() - p[i].is_die > data->die)
			{
				pthread_mutex_lock(p->wr);
				time = gettime() - data->start;
				printf("\033[1;31m\n%5ld ms %zu is die\n\n", time, p->np);
				return (0);
			}
			i++;
		}
		if (!check_neat(data, p))
			return (0);
	}
}

int	ft_pthreads(t_data *data, t_philo *p)
{
	size_t	i;

	i = 0;
	while (i < data->philo)
	{
		p[i].is_die = gettime();
		if (pthread_create(&p[i].th, NULL, ft_philo, &p[i]))
			return (1);
		usleep(100);
		i++;
	}
	if (!check_dieing(data, p))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		*data;
	t_philo		*p;
	size_t		i;

	data = malloc(sizeof(t_data));
	if (ac < 5 || ac > 6)
		ft_error("Arg number error!!");
	if(!ft_data_fill(data, av, ac))
		return (1);
	p = malloc(sizeof(t_philo) * data->philo);
	if (!p)
		ft_error("malloc error!!");
	i = 0;
	while (i++ < data->philo)
		pthread_mutex_init(&data->forks[i], NULL);
	pthread_mutex_init(&data->wr, NULL);
	ft_data_match(p, data);
	data->start = gettime();
	if (ft_pthreads(data, p))
		return (1);
	return (0);
}

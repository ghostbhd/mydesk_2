/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:54:28 by abouhmad          #+#    #+#             */
/*   Updated: 2022/04/25 03:09:51 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	gettime()
{
	struct timeval t;
	
	gettimeofday(&t, NULL);
	return((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_usp(size_t tm)
{
	size_t	now;
	
	now = gettime();
	while (1)
	{
		usleep(20);
		if(gettime() - now >= tm)
			break ;
	}
}

void	*m_msg(t_philo *p, char *msg)
{
	size_t	time;
	pthread_mutex_lock(p->wr);
	time = gettime() - p->d->start;
	printf("%5ld ms %zu %s\n",time, p->np, msg);
	pthread_mutex_unlock(p->wr);
	return (0);
}

void	*ft_philo(void *philo)
{
	t_philo *p;

	p = (t_philo *) philo;
	
	if (p->d->philo % 2)
		usleep(1500);
	while (1)
	{
		if (gettime() - p->is_die >= p->d->die)
			return (0);
		pthread_mutex_lock(p->rfork);
		m_msg(p, "has take a fork");
		pthread_mutex_lock(p->lfork);
		m_msg(p, "has take a fork");
		m_msg(p, "is eating");
		p->is_die = gettime();
		usleep(p->d->eat * 1000);
		pthread_mutex_unlock(p->rfork);
		pthread_mutex_unlock(p->lfork);
		m_msg(p, "is sleeping");
		usleep(p->d->sleep * 1000);
		m_msg(p, "is thinking");
	}
	return (0);
}

int main(int ac, char **av)
{
	t_data		*data;
	t_philo		*p;
	size_t		i;

	data = malloc(sizeof(t_data));
	if (ac < 5 || ac > 6)
		ft_error("Arg number error!!");
	//fill data---------------------------------------
	data->philo = ft_atoi(av[1]);
	data->die = ft_atoi(av[2]);
	data->eat = ft_atoi(av[3]);
	data->sleep = ft_atoi(av[4]);
	data->neat = -1;
	if (ac == 6)
		data->neat = ft_atoi(av[5]);
	p = malloc(sizeof(t_philo) * data->philo);
	if (!p)
		ft_error("malloc error!!");
	//match data--------------------------------------
	i = 0;
	while (i < data->philo)
	{
		p[i].d = data;
		p[i].wr = &data->wr;
		p[i].np = i + 1;
		i++;
	}
	//forks-------------------------------------------
	data->start = gettime();
    p[0].rfork = &p[0].forks;
    p[0].lfork = &p[data->philo - 1].forks;
	i = 1;
	while (i < data->philo)
    {
        p[i].rfork = &p[i].forks;
        p[i].lfork = &p[i - 1].forks;
		p[i].d->start = data->start;
		i++;
    }
	//mutex init---------------------------------------
	pthread_mutex_init(&data->wr, NULL);
	i = 0;
	while (i++ < data->philo)
		pthread_mutex_init(&p[i].forks, NULL);
	//pthread create-----------------------------------
	i = 0;
	while (i < data->philo)
	{
		p[i].is_die = gettime();
		if (pthread_create(&p[i].th, NULL, ft_philo, &p[i]))
			ft_error("Pthread Create error!!");
		// usleep(150);
		i++;
	}
	//pthread join-------------------------------------
	i = 0;
	while (i < data->philo)
	{
		if (pthread_join(p[i].th, NULL))
			ft_error("Pthread Join error!!");
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < data->philo)
		{
			if (gettime() - p[i].is_die > data->die)
			{
				pthread_mutex_lock(p->wr);
				printf("%5ld ms %zu is die\n",gettime() - data->start, p->np);
				return (0);
			}
			i++;
		}
	}
	//mutex destroy-------------------------------------
	i = 0;
	while (i++ < data->philo)
		pthread_mutex_destroy(&p[i].forks);
	pthread_mutex_destroy(&data->wr);
	return (0);
}

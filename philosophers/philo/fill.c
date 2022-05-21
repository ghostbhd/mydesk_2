/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:05:50 by abouhmad          #+#    #+#             */
/*   Updated: 2022/05/21 14:44:06 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_data_fill(t_data *data, char **av, int ac)
{
	data->philo = ft_atoi(av[1]);
	if (data->philo == 0)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo);
	data->die = ft_atoi(av[2]);
	data->eat = ft_atoi(av[3]);
	data->sleep = ft_atoi(av[4]);
	data->neat = 0;
	if (ac == 6)
		data->neat = ft_atoi(av[5]);
	if (ac == 6 && data->neat == 0)
		return (0);
	return (1);
}

void	ft_data_match(t_philo *p, t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo)
	{
		p[i].d = data;
		p[i].wr = &data->wr;
		p[i].np = i + 1;
		i++;
	}
	i = 0;
	while (i < data->philo)
	{
		p[i].rfork = &data->forks[i];
		if (i != 0)
			p[i].lfork = &data->forks[i - 1];
		else
			p[i].lfork = &data->forks[data->philo - 1];
		p[i].d->start = data->start;
		p[i].p_neat = data->neat;
		i++;
	}
}

void	ft_is(t_philo *p)
{
	m_msg(p, "is sleeping");
	ft_usp(p->d->sleep * 1000);
	m_msg(p, "is thinking");
}

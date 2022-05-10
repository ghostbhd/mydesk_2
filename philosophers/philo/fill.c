/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:05:50 by abouhmad          #+#    #+#             */
/*   Updated: 2022/05/10 17:08:01 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_data_fill(t_data *data, char **av, int ac)
{
	data->philo = ft_atoi(av[1]);
	if (data->philo == 0)
		exit(1);
	data->die = ft_atoi(av[2]);
	data->eat = ft_atoi(av[3]);
	data->sleep = ft_atoi(av[4]);
	data->neat = 0;
	if (ac == 6)
		data->neat = ft_atoi(av[5]);
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
	data->start = gettime();
	p[0].rfork = &p[0].forks;
	p[0].lfork = &p[data->philo - 1].forks;
	i = 1;
	while (i < data->philo)
	{
		p[i].rfork = &p[i].forks;
		p[i].lfork = &p[i - 1].forks;
		p[i].d->start = data->start;
		p[i].p_neat = data->neat;
		i++;
	}
}

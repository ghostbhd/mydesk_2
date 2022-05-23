/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 02:41:23 by abouhmad          #+#    #+#             */
/*   Updated: 2022/05/23 16:58:38 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - 48;
		if (INT32_MAX < nbr)
			return (-1);
		i++;
	}
	if (str[i] != '\0' || str[0] == '\0')
		return (-1);
	return (nbr);
}

ssize_t	gettime(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_usp(ssize_t tm)
{
	ssize_t	now;

	now = gettime();
	usleep(tm - 10000);
	while (1)
	{
		if (gettime() - now >= tm / 1000)
			break ;
		usleep(300);
	}
}

void	*m_msg(t_philo *p, char *msg)
{
	ssize_t	time;

	pthread_mutex_lock(p->wr);
	time = gettime() - p->d->start;
	printf("%5ld ms %zu %s\n", time, p->np, msg);
	pthread_mutex_unlock(p->wr);
	return (0);
}

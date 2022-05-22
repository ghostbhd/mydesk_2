/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 02:41:23 by abouhmad          #+#    #+#             */
/*   Updated: 2022/05/22 18:30:25 by abouhmad         ###   ########.fr       */
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
			return (printf("MAX int error!!") * -1);
		i++;
	}
	if (str[i] != 0 || str[0] == '\0')
		return (printf("Number error!!") * -1);
	return (nbr);
}

void	ft_error(char *msg)
{
	printf("%s\n", msg);
	exit (EXIT_FAILURE);
}

size_t	gettime(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_usp(size_t tm)
{
	size_t	now;

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
	size_t	time;

	pthread_mutex_lock(p->wr);
	time = gettime() - p->d->start;
	printf("%5ld ms %zu %s\n", time, p->np, msg);
	pthread_mutex_unlock(p->wr);
	return (0);
}

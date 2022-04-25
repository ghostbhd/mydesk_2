/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:55:03 by abouhmad          #+#    #+#             */
/*   Updated: 2022/04/25 01:05:00 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	pthread_mutex_t	wr;
	size_t			eat;
	size_t			die;
	size_t			neat;
	size_t			sleep;
	size_t			start;
	size_t			philo;
}	t_data;

typedef struct s_philo
{
	pthread_t		th;
	pthread_mutex_t	forks;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*wr;
	t_data			*d;
	size_t			np;
	size_t			is_die;
}	t_philo;

//utils
void	ft_error(char *msg);
int		ft_atoi(const char *str);
size_t	gettime();
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:55:03 by abouhmad          #+#    #+#             */
/*   Updated: 2022/05/22 17:30:46 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	pthread_mutex_t	wr;
	pthread_mutex_t	lock;
	size_t			eat;
	size_t			die;
	size_t			neat;
	size_t			sleep;
	size_t			start;
	size_t			philo;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philo
{
	t_data			*d;
	pthread_t		th;
	size_t			np;
	pthread_mutex_t	*wr;
	pthread_mutex_t	oop;
	size_t			rfork;
	size_t			lfork;
	size_t			is_die;
	size_t			p_neat;
}	t_philo;

//utils
void	*m_msg(t_philo *p, char *msg);
int		ft_atoi(const char *str);
void	ft_error(char *msg);
void	ft_usp(size_t tm);
void	ft_is(t_philo *p);
size_t	gettime(void);

//fill
int		ft_data_fill(t_data *data, char **av, int ac);
void	ft_data_match(t_philo *p, t_data *data);
#endif
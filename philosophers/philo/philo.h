/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:55:03 by abouhmad          #+#    #+#             */
/*   Updated: 2022/05/23 17:26:04 by abouhmad         ###   ########.fr       */
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
	ssize_t			eat;
	ssize_t			die;
	ssize_t			neat;
	ssize_t			sleep;
	ssize_t			start;
	ssize_t			philo;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philo
{
	t_data			*d;
	pthread_t		th;
	ssize_t			np;
	pthread_mutex_t	*wr;
	pthread_mutex_t	oop;
	ssize_t			rfork;
	ssize_t			lfork;
	ssize_t			is_die;
	ssize_t			p_neat;
}	t_philo;

//utils
void	*m_msg(t_philo *p, char *msg);
int		ft_atoi(const char *str);
void	ft_usp(ssize_t tm);
void	ft_is(t_philo *p);
ssize_t	gettime(void);
int		ft_check_nbr(int ac, char **av);

//fill
int		ft_data_fill(t_data *data, char **av, int ac);
void	ft_data_match(t_philo *p, t_data *data);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 02:41:23 by abouhmad          #+#    #+#             */
/*   Updated: 2022/04/22 23:48:15 by abouhmad         ###   ########.fr       */
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
			ft_error("Max error!!");
		i++;
	}
	if (str[i] != 0 || str[0] == '\0')
		ft_error("Number error!!");
	return (nbr);
}

void	ft_error(char *msg)
{
	printf("%s\n", msg);
	exit (EXIT_FAILURE);
}
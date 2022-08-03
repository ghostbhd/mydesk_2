/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:29:19 by abouhmad          #+#    #+#             */
/*   Updated: 2022/08/03 01:40:13 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_white_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	is_separate(char c)
{
	if (c == '<' || c == '>' || c == '|' || \
		c == '\"' || c == '\'')
		return (1);
	return (0);
}

void	ft_error(char *msg)
{
	printf ("%s\n", msg);
	exit(1);
}

int	check_d(char c)
{
	if (is_alpha(c) || c == '_')
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:45:31 by abouhmad          #+#    #+#             */
/*   Updated: 2022/06/13 22:40:06 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// | "
void	parsser(char *line, t_put *put, t_token *mini, t_tree tree)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (is_white_space(line[i]))
			i++;
		j = i;
		while (!is_separate(line[i]))
			i++;
		mini->cmd = ft_str
		i++;
	}
}

char	*get_text(char *line, int start)
{
	int	flag;

	flag = 0;
}

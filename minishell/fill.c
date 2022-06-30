/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:45:31 by abouhmad          #+#    #+#             */
/*   Updated: 2022/06/30 01:06:34 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//  |  '  "  <  >  <<  >>
void	parsser(char *line, t_list **mini)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (is_white_space(line[i]) && line[i])
			i++;
		j = i;
		if (is_separate(line[i]))
			i = get_cmd(line, i, mini);
		else if (line[i])
			i = get_file(line, i );
		i++;
	}
}



/* struct fill
{
	int i;
	char *cont;
	char c;	
	int str_len;

};

struct fill
{
	cont
	ar 
	type
}; */



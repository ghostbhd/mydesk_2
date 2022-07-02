/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:45:31 by abouhmad          #+#    #+#             */
/*   Updated: 2022/07/02 16:08:18 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//  |  '  "  <  >  <<  >>
void	fill_env(t_env **list_env, char **env)
{
	int	i;
	
	i = 0;
	while (env[i])
	{
		
	}
}

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

char	get_env_value(char *key, char *line)
{
	int	i;

	
}

void	ft_dollar(char *line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		while (is_white_space(line[i]) && line[i])
			i++;
		if (line[i] == '\'')
		{
			while (line[i] != '\'')
				i++;
			i++;
		}
		else if (line[i] == '$')
		{
			j = i + 1;
			if (ft_isalpha(line[i + 1]) || line[i + 1] == '_')
			{
				i++;
				while (ft_isalnum(line[i]) || line[i] == '_')
					i++;
				
			}
		}
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



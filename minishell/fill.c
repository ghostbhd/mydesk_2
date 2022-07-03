/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:45:31 by abouhmad          #+#    #+#             */
/*   Updated: 2022/07/03 02:57:10 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//  |  '  "  <  >  <<  >>
void	fill_env(t_env **list_env, char **env)
{
	int		i;
	int		j;
	char	**split;
	
	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j])
		{
			if (env[i][j] == '=')
			{
				ft_envadd_back(list_env, ft_envnew(ft_substr\
				(env[i], 0, j), ft_strdup(env[i] + j + 1)));
				break ;
			}
			j++;
		}
		i++;
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

int	ft_dollar(char *line, int start, t_list **mini)
{
	int	i;

	i == start + 1;
	if (ft_isalpha(line[i]) || line[i] == '_')
	{
		while ((ft_isalnum(line[i]) || line[i]) == '_' && line[i])
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



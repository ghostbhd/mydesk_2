/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:45:31 by abouhmad          #+#    #+#             */
/*   Updated: 2022/07/31 03:23:10 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//  |  '  "  <  >  <<  >>
void	fill_env(t_env **envlst, char **env)
{
	int		i;
	int		j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j])
		{
			if (env[i][j] == '=')
			{
				ft_envadd_back(envlst, ft_envnew(ft_substr\
				(env[i], 0, j), ft_strdup(env[i] + j + 1)));
				break ;
			}
			j++;
		}
		i++;
	}
}

int	add_cmd(char *line, t_list **mini, int start)
{
	int	i;
	int j;

	i = start;
	j = start;
	while (!is_white_space(line[i]) && !is_separate(line[i]) && line[i])
		i++;
	if (ft_lstlast(*mini)->token == CMD)
		ft_cmdadd(&ft_lstlast(*mini)->cmd, ft_cmdnew(ft_substr(line, j, i - j)));
	else
		ft_lstadd(mini, ft_lstnew(CMD, ft_cmdnew(ft_substr(line, j, i - j))));
	return (i);
}

void	parsser(char *line, t_list **mini, t_env *envlst)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (is_white_space(line[i]))
			i++;
		if (is_separate(line[i]))
			i = get_cmd(line, i, mini, envlst);
		else
			i = add_cmd(line, mini, i);
		
		// printf("done ; \n");//test
	}
}

void	get_evalue(int choix, char *key, t_list **mini, t_env *envlst)
{
	t_env	*tmp;

	tmp = envlst;
	while (tmp)
	{
		if (!ft_strncmp(key, tmp->key, ft_strlen(key)))
		{
			ft_cmdadd(&(*mini)->cmd, ft_cmdnew(ft_strdup(tmp->value)));
			return ;
		}
		tmp = tmp->next;
	}
	if (choix)
		ft_cmdadd(&(*mini)->cmd, ft_cmdnew(ft_strdup("")));
}

int	ft_dollar(char *line, int start, t_list **mini, t_env *envlst)
{
	int	i;

	i = start + 1;
	if (ft_isalpha(line[i]) || line[i] == '_')
	{
		while ((ft_isalnum(line[i]) || line[i] == '_') && line[i])
			i++;
		if (!is_white_space(line[i]) && !is_separate(line[i]) && line[i])
		{
			get_evalue(1, ft_substr(line, start + 1, i - start - 1), mini, envlst);
			start = i;
			while (!is_white_space(line[i]) && !is_separate(line[i]) && line[i])
				i++;
		}
		else
			get_evalue(0, ft_substr(line, start + 1, i - start - 1), mini, envlst);
	}
	return (i);
}


//line = ft_strjoin(ft_getdollarvalue("$test"), line + i);
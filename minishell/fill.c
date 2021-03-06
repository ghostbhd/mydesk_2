/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:45:31 by abouhmad          #+#    #+#             */
/*   Updated: 2022/08/03 10:06:41 by abouhmad         ###   ########.fr       */
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
				ft_envadd_back(envlst, ft_envnew(ft_substr(\
				env[i], 0, j), ft_strdup(env[i] + j + 1)));
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
	int	j;

	i = start;
	j = start;
	while (!is_white_space(line[i]) && !is_separate(line[i]) && line[i])
		i++;
	if (ft_lstlast(*mini) != 0 && ft_lstlast(*mini)->token == CMD)
		ft_cmdadd(&ft_lstlast(*mini)->cmd, ft_cmdnew(\
		ft_substr(line, j, i - j)));
	else
		ft_lstadd(mini, ft_lstnew(CMD, ft_cmdnew(ft_substr(line, j, i - j))));
	return (i);
}

void	parsser(char *line, t_data **data, t_env *envlst)
{
	int		i;
	t_list	*mini;

	i = 0;
	mini = 0;
	(void) data;
	while (line[i])
	{
		while (is_white_space(line[i]))
			i++;
		if (is_separate(line[i]))
			i = get_cmd(line, i, &mini, envlst);
		else
			i = add_cmd(line, &mini, i);
	}
	list_print(mini);
	// ft_readlst(mini, data);
	ft_lstclear(&mini);
}

char	*ft_key(t_env *envlst, char *key)
{
	t_env	*tmp;

	tmp = envlst;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen(tmp->key)))
		{
			free(key);
			return (ft_strdup(tmp->value));
		}
		tmp = tmp->next;
	}
	return (ft_strdup(""));
}

char	*ft_d(char *line, int len, t_env *envlst)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (ft_strchr(line, '$'))
	{
		while (line[i])
		{
			if (line[i] == '$')
			{
				if (check_d(line[i + 1]))
				{
					str = ft_substr(line, 0, i);
					str = ft_strjoin(str, ft_d(line + i + 1, len, envlst));
				}
				else
				{
					str = ft_substr(line, 0, i);
					j = i + 1;
					while (j < len && (ft_isalnum(line[j]) || line[j] == '_'))
						j++;
					str = ft_strjoin(str, ft_key(envlst, ft_substr(line, i + 1, j - i - 1)));
					str = ft_strjoin(str, ft_d(line + i, len - i, envlst));
					return (str);
				}
			}
			i++;
		}
	}
	else
		return (ft_substr(line, 0, len));
}

/* void	get_evalue(int choix, char *key, t_list **mini, t_env *envlst)
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
		ft_cmdadd(&ft_lstlast(*mini)->cmd, ft_cmdnew(ft_strdup("")));
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
			get_evalue(1, ft_substr(line, start + 1, i - start - 1), \
			mini, envlst);
			start = i;
			while (!is_white_space(line[i]) && !is_separate(line[i]) && line[i])
				i++;
		}
		else
			get_evalue(0, ft_substr(line, start + 1, i - start - 1), \
			mini, envlst);
	}
	return (i);
} */

// echo hello$USER.com   hello  abouhmad .com
// echo hello$.USER.com   hello  abouhmad .com 
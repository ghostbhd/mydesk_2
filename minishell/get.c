/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:38:01 by abouhmad          #+#    #+#             */
/*   Updated: 2022/07/06 22:07:52 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//get text -----------------------------------------------------------
int	get_text(char *line, int start, t_list **mini, char check)
{
	int	i;
	
	i = start;
	while (line[i] != check && line[i])
		i++;
	if (line[i] == check)
    {
		ft_cmdadd_back(&(*mini)->cmd, ft_cmdnew(ft_substr(line, start, i)));
		return (i + 1);
    }
	else
		ft_error("bash: syntax error");
}

//get file -----------------------------------------------------------

void	ft_redi(char *line, int i, t_list **mini, char check)
{
	if (line[i - 1] == check && line[i - 2] == check)
	{
		if (check == '<')
			ft_lstadd_back(mini, ft_lstnew(HERD, 0));
		else
			ft_lstadd_back(mini, ft_lstnew(APPEND, 0));
	}
	else
	{
		if (check == '<')
			ft_lstadd_back(mini, ft_lstnew(RED_IN, 0));
		else
			ft_lstadd_back(mini, ft_lstnew(RED_OUT, 0));
	}
}

int	get_file(char *line, int start, t_list **mini, char check)
{
	int	i;

	i = start;
	ft_redi(line, i, mini, check);
	while (is_white_space(line[i]) && line[i])
		i++;
	if (!is_separate(line[i]) && line[i])
	{
		start = i;
		while (!is_separate(line[i]) && !is_white_space(line[i]) && line[i])
			i++;
		ft_lstlast(*mini)->cmd = ft_substr(line, start, i - start);
	}
	else if (line[i] == '\'' || line[i] == '"')
		i = get_text(line, i, mini, line[i]);
	else
		ft_lstlast(*mini)->token = ERROR;
	return (i);
}

//get command ---------------------------------------------------------
int get_cmd(char *line, int start, t_list **mini, t_env *envlst)
{
	char	check;

	check = line[start];
	if (check == '|')
	{
		ft_lstadd_back(mini, ft_lstnew(PIPE, ft_cmdnew(ft_strdup("|"))));
		start++;
	}
	else if (check == '"' || check == '\'')
		start = get_text(line, start + 1, mini, check);
	else if ( check == '<' || check == '>')
	{
		if (line[start + 1] == check)
			start = get_file(line, start + 2, mini, check);
		else
			start = get_file(line, start + 1, mini, check);
	}
	else if (check == '$')
	{
		
	}
	return (start);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:38:01 by abouhmad          #+#    #+#             */
/*   Updated: 2022/08/02 17:25:49 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//get text -----------------------------------------------------------

int	is_redirect(t_list **mini)
{
	int		i;
	char	*tmp;

	i = ft_lstlast(*mini)->token;
	tmp = ft_lstlast(*mini)->cmd->content;
	if (tmp && (i == RED_IN || i == RED_OUT || i == HERD || i == APPEND))
		return (1);
	return (0);
}

int	get_text(char *line, int start, t_list **mini, char check)
{
	int	i;

	i = start;
	while (line[i] != check && line[i])
		i++;
	if (line[i] == check)
	{
		if (ft_lstlast(*mini) == 0 || ft_lstlast(*mini)->token == PIPE \
		|| is_redirect(mini))
			ft_lstadd(mini, ft_lstnew(CMD, ft_cmdnew(\
			ft_substr(line, start, i - start))));
		else
			ft_cmdadd(&ft_lstlast(*mini)->cmd, ft_cmdnew(\
			ft_substr(line, start, i - start)));
		return (i + 1);
	}
	else
	{
		if (ft_lstlast(*mini) == 0 || ft_lstlast(*mini)->token == PIPE)
			ft_lstadd(mini, ft_lstnew(ERROR, ft_cmdnew(ft_strdup(""))));
		else
			ft_lstlast(*mini)->token = ERROR;
	}
	return (i);
}

//get file -----------------------------------------------------------

void	ft_redi(char *line, int i, t_list **mini, char check)
{
	if (i > 1 && line[i - 1] == check && line[i - 2] == check)
	{
		if (check == '<')
			ft_lstadd(mini, ft_lstnew(HERD, 0));
		else
			ft_lstadd(mini, ft_lstnew(APPEND, 0));
	}
	else
	{
		if (check == '<')
			ft_lstadd(mini, ft_lstnew(RED_IN, 0));
		else
			ft_lstadd(mini, ft_lstnew(RED_OUT, 0));
	}
}

int	get_file(char *line, int start, t_list **mini, char check)
{
	int	i;

	i = start;
	ft_redi(line, i, mini, check);
	while (is_white_space(line[i]) && line[i])
		i++;
	if (!is_separate(line[i]))
	{
		start = i;
		while (!is_separate(line[i]) && !is_white_space(line[i]) && line[i])
			i++;
		ft_cmdadd(&ft_lstlast(*mini)->cmd, ft_cmdnew(\
		ft_substr(line, start, i - start)));
	}
	else
	{
		if (line[i] == '\'' || line[i] == '"')
			i = get_text(line, i + 1, mini, line[i]);
		else
			ft_lstlast(*mini)->token = ERROR;
	}
	return (i);
}

//get command ---------------------------------------------------------

int	get_cmd(char *line, int start, t_list **mini, t_env *envlst)
{
	char	check;

	(void) envlst;
	check = line[start];
	if (check == '|')
	{
		ft_lstadd(mini, ft_lstnew(PIPE, ft_cmdnew(ft_strdup("|"))));
		start++;
	}
	else if (check == '"' || check == '\'')
		start = get_text(line, start + 1, mini, check);
	else if (check == '<' || check == '>')
	{
		if (line[start + 1] == check)
			start = get_file(line, start + 2, mini, check);
		else
			start = get_file(line, start + 1, mini, check);
	}
	return (start);
}

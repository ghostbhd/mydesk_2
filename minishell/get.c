/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:38:01 by abouhmad          #+#    #+#             */
/*   Updated: 2022/06/29 23:56:41 by abouhmad         ###   ########.fr       */
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
int	get_file(char *line, int start, t_list **mini)
{
	int	i;

	i = start;
	while (is_white_space(line[i]) && line[i])
		i++;
	if (!is_separate(line[i]) && line[i])
	{
		start = i;
		while (!is_separate(line[i]) && !is_white_space(line[i]) && line[i])
			i++;
	}
}

//get command ---------------------------------------------------------
int get_cmd(char *line, int start, t_list **mini)
{
	int		i;
	char	check;
	
	i = 0;
	check = line[start];
	if (check == '|')
	{
		ft_lstadd_back(mini, ft_lstnew(PIPE, ft_cmdnew(ft_strdup("|"))));
		return (start + 1);
	}
	else if (check == '"' || check == '\'')
	{
		start = get_text(line, start + 1, mini, check);
		return (start);
	}
	else if ( check == '<' || '>')
	{
		//get_file;
		if (line[start + 1] == check)
			start = get_file(line, start + 2, mini);
		else
			start = get_file(line, start + 1, mini);
	}
	
}

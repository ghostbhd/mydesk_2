/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:38:01 by abouhmad          #+#    #+#             */
/*   Updated: 2022/06/25 23:44:25 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_text(char *line, int start, t_list **mini, char check)
{
	int	i;
	
	while (line[start + i] != check && line[start + i])
		i++;
	if (line[start + i] == check)
    {
        ft_cmdadd_back(&(*mini)->cmd, ft_cmdnew(ft_substr(line, start, i)));
        return (start + i + 1);
    }
    else
        ft_error("bash: syntax error: unexpected end of file");
}

int get_cmd(char *line, int start, t_list **mini)
{
	int i;
    char    check;

	i = 0;
    check = line[start];
    if (check == '|')
    {
        ft_lstadd_back(mini, ft_lstnew(PIPE, 0));
        ft_lstlast(*mini)->cmd = ft_cmdnew("|");
        return (start + 1);
    }
    else if (check == '"' || check == '\'')
        start = get_text(line, start + 1, mini, check);
}

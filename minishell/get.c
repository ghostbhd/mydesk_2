/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:38:01 by abouhmad          #+#    #+#             */
/*   Updated: 2022/06/21 18:16:19 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int *get_cmd(char *line, int start, t_list **mini)
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
    {
        //get text;
    }
}

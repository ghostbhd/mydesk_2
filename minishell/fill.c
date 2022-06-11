/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:45:31 by abouhmad          #+#    #+#             */
/*   Updated: 2022/06/11 19:44:45 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    parsser(char *line, t_put *put, t_token *mini, t_tree tree)
{
    int i;
    int j;
    int flag;
    
    i = 0;
    j = 0;
    flag = 0;
    while (line[i])
    {
        while(line[i] == ' ' || (9 <= line[i] && line[i] <= 13))
            i++;
        j = i;
        i++;
    }
}
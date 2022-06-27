/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:36:26 by abouhmad          #+#    #+#             */
/*   Updated: 2022/06/21 18:11:53 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_list	*ft_lstnew(int token, t_cmd *cmd)
{
	t_list	*p;

	p = (t_list *)malloc(sizeof(t_list));
	if (!p)
		return (0);
	p->token = token;
	p->cmd = cmd;
	p -> next = 0;
	return (p);
}

t_cmd *ft_cmdnew(char *content)
{
	t_cmd	*p;
	p = malloc (sizeof(t_cmd));
	if (!p)
		return (0);
	p->content = content;
	p->next = 0;
	return (p);
}
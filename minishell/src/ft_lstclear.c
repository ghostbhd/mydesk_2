/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:48:40 by abouhmad          #+#    #+#             */
/*   Updated: 2022/07/31 03:29:31 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*c;
	t_cmd	*tmp;

	while (*lst)
	{
		c = (*lst)->next;
		if ((*lst)->cmd->next != NULL)
		{
			while ((*lst)->cmd)
			{
				tmp = (*lst)->cmd->next;
				free((*lst)->cmd);
				(*lst)->cmd = tmp;
			}
		}
		free(*lst);
		*lst = c;
	}
	*lst = 0;
}

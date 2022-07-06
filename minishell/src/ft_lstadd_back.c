/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:46:35 by abouhmad          #+#    #+#             */
/*   Updated: 2022/07/06 22:54:11 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_lstadd(t_list **lst, t_list *new)
{
	if (*lst == 0)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

void	ft_cmdadd(t_cmd **lst, t_cmd *new)
{
	if (*lst == 0)
		*lst = new;
	else
		ft_cmdlast(*lst)->next = new;
}

void	ft_envadd_back(t_env **lst, t_env *new)
{
	if (*lst == 0)
		*lst = new;
	else
		ft_cmdlast(*lst)->next = new;
}

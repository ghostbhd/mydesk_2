/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:37:32 by abouhmad          #+#    #+#             */
/*   Updated: 2022/06/28 19:13:33 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	char	*line = "  cat Makefile | grep \"util\" <infile";
	t_list	*mini;
	t_tree	*tree;

	mini = ft_lstnew(1, 0);
	mini->cmd = ft_cmdnew("hellooooooo") ;
	ft_cmdadd_back(&mini->cmd, ft_cmdnew("bro"));
	ft_cmdadd_back(&mini->cmd, ft_cmdnew("."));
	printf("%d\n", ft_cmdsize(mini->cmd));
	while (mini->cmd)
	{
		printf("%s\n", mini->cmd->content);
		mini->cmd = mini->cmd->next;
	}
	
	return (0);
}

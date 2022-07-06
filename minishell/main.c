/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:37:32 by abouhmad          #+#    #+#             */
/*   Updated: 2022/07/03 15:43:01 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av, char **env)
{
	char	*line = "  cat Makefile | grep \"util\" <infile";
	t_list	*mini;
	t_env	*envlst;

	
	mini = ft_lstnew(PIPE, 0);
	mini->cmd = ft_cmdnew("hellooooooo");
	ft_cmdadd_back(&mini->cmd, ft_cmdnew("bro"));
	ft_cmdadd_back(&mini->cmd, ft_cmdnew(ft_strdup("how are you ?")));
	mini->token = ERROR;

	ft_lstadd_back(&mini, ft_lstnew(RED_IN, 0));
	ft_cmdadd_back(&mini->cmd, ft_cmdnew("mini"));
	ft_cmdadd_back(&mini->cmd, ft_cmdnew("second"));
	printf("Token: %d\n", mini->token);
	printf("List size: %d\n", ft_cmdsize(mini->cmd));
	while (mini->cmd)
	{
		printf("%s\n", mini->cmd->content);
		mini->cmd = mini->cmd->next;
	}
	
	mini = mini->next;
	printf("Token: %d\n", mini->token);
	while (mini->cmd)
	{
		printf("%s\n", mini->cmd->content);
		mini->cmd = mini->cmd->next;
	}
	

	return (0);
}

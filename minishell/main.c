/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:37:32 by abouhmad          #+#    #+#             */
/*   Updated: 2022/07/21 19:18:46 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(void)
{
	char	*line;
	t_list	*mini;
	t_env	*envlst;
	t_list	*tmp;
	t_cmd	*ctmp;

	envlst = NULL;
	line = ft_strdup("  cat Makefile | wc -la");
	parsser(line, &mini, envlst);
	tmp = mini;
	while (tmp)
	{
		printf("%d ", tmp->token);
		ctmp = tmp->cmd;
		while (ctmp)
		{
			printf("%s ", ctmp->content);
			ctmp = ctmp->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

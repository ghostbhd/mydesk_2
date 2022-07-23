/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:37:32 by abouhmad          #+#    #+#             */
/*   Updated: 2022/07/23 19:16:09 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_tok(int tok)
{
	if (tok == 0)
		return ("CMD");
	else if (tok == 1)
	 	return ("PIPE");
	else if (tok == 2)
	 	return ("RED_IN");
	else if (tok == 3)
	 	return ("RED_OUT");
	else if (tok == 4)
	 	return ("APPEND");
	else if (tok == 5)
	 	return ("HERD");
	else
		return ("ERROR");
}

void	list_print(t_list *mini)
{
	t_list	*tmp;
	t_cmd	*cmd;

	tmp = mini;
	while (tmp)
	{
		printf("%s ", ft_tok(tmp->token));
		cmd = tmp->cmd;
		while (cmd)
		{
			printf("%s ", cmd->content);
			cmd = cmd->next;
		}
		tmp = tmp->next;
	}
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_list	*mini;
	t_env	*envlst;
	t_list	*tmp;
	t_cmd	*ctmp;

	(void) ac;
	(void) av;
	fill_env(&envlst, env);
	line = ft_strdup("cat Makefile | wc -la");
	printf("%s\n", line);
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

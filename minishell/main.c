/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:37:32 by abouhmad          #+#    #+#             */
/*   Updated: 2022/08/02 15:09:13 by abouhmad         ###   ########.fr       */
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
		printf("\n==> %9s   ", ft_tok(tmp->token));
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
	t_env	*envlst;
	t_data	*data;

	(void) ac;
	(void) av;
	(void) env;
	envlst = 0;
	fill_env(&envlst, env);
	while (1)
	{
		line = readline("\n mini $> ");
		add_history(line);
		parsser(line, &data, envlst);
	}
	return (0);
}

//	line = ft_strdup(">  how  cat <Makefile >hola >>lim | wc -la '-a'");

//	==>       CMD	
//	==>   RED_OUT	how
//	==>       CMD	cat
//	==>    RED_IN	Makefile
//	==>   RED_OUT	hola
//	==>    APPEND	lim
//	==>      PIPE	|
//	==>       CMD	wc -la -a %
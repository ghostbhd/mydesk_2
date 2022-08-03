/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:43:27 by abouhmad          #+#    #+#             */
/*   Updated: 2022/08/03 01:41:05 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

enum e_title
{
	CMD,
	PIPE,
	RED_IN,
	RED_OUT,
	APPEND,
	HERD,
	ERROR
};

typedef struct s_cmd
{
	char			*content;
	struct s_cmd	*next;
}t_cmd;

typedef struct s_list
{
	int				token;
	t_cmd			*cmd;
	struct s_list	*next;
}t_list;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}t_env;

typedef struct s_tree
{
	char			*content;
	struct s_tree	*left;
	struct s_tree	*right;
}t_tree;

typedef struct s_data
{
	char			**cmd;
	char			**infile;
	char			**outfile;
	char			**append;
	char			**herd;
	int				error;
	struct s_data	*next;
}t_data;

//src -----------------------------------------------------------------

//List *****************
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd(t_list **lst, t_list *new);
t_list	*ft_lstnew(int token, t_cmd *cmd);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
//List > cmd ______
void	ft_cmdadd(t_cmd **lst, t_cmd *new);
t_cmd	*ft_cmdnew(char *content);
int		ft_cmdsize(t_cmd *lst);
t_cmd	*ft_cmdlast(t_cmd *lst);
//List > env
void	ft_envadd_back(t_env **lst, t_env *new);
t_env	*ft_envlast(t_env *lst);
int		ft_envsize(t_env *lst);
t_env	*ft_envnew(char *key, char *value);
//List > data
t_data	*ft_datalast(t_data *lst);
t_data	*ft_datanew(void);
//----------------------------------------------------------------------

//is functions
int		is_white_space(char c);
int		is_separate(char c);

//get functions
int		get_cmd(char *line, int start, t_list **mini, t_env *envlst);
int		get_file(char *line, int start, t_list **mini, char check);
int		get_text(char *line, int start, t_list **mini, char check);
void	ft_redi(char *line, int i, t_list **mini, char check);

//Utils functions
void	ft_error(char *msg);

//Main functions
void	parsser(char *line, t_data **data, t_env *envlst);
void	fill_env(t_env **envlst, char **env);
// void	ft_readlst(t_list *lst, t_data **data);

//dollor functions
int	check_d(char c);

//--> just test
void	list_print(t_list *mini);

#endif
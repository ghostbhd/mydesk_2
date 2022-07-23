/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:43:27 by abouhmad          #+#    #+#             */
/*   Updated: 2022/07/23 03:53:59 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

enum title
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
} t_cmd;

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

//src ------------------------------------------------------------------
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char *str, char c);
char	*ft_strndup(char *s1, int n);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isalnum(int c);

//List *****************
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd(t_list **lst, t_list *new);
t_list	*ft_lstnew(int token, t_cmd *cmd);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
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
void	parsser(char *line, t_list **mini, t_env *envlst);
void	fill_env(t_env **envlst, char **env);

//--> just test
void	list_print(t_list *mini);

#endif
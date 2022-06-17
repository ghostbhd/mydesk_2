/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:43:27 by abouhmad          #+#    #+#             */
/*   Updated: 2022/06/16 18:34:07 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef enum 
{
	CMD,
	PIPE,
	RED,
	HERD
} t_tok;

typedef struct s_put
{
	int	in;
	int	out;
	int	err;
}t_put;

typedef struct s_option
{
	char			*content;
	struct s_option	*next;
} t_option;


typedef struct s_list
{
	t_tok			*token;
	char			*cmd;
	t_option		*opt;
	t_put			put;
	struct s_token	*next;
}t_list;

typedef struct s_tree
{
	char			*content;
	struct s_tree	*left;
	struct s_tree	*right;
}t_tree;

//src ------------------------------------------------------------------
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char *str, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
//List ****
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(char *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(char *content);
int		ft_lstsize(t_list *lst);
//----------------------------------------------------------------------

//is function
int		is_white_space(char c);
int		is_separate(char c);


#endif
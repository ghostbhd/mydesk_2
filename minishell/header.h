/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:43:27 by abouhmad          #+#    #+#             */
/*   Updated: 2022/06/08 18:37:49 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

//src ------------------------------------------------------------------
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char *str, char c);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
//----------------------------------------------------------------------

typedef struct s_put
{
	int				input;
	int				output;
	int				error;
} t_put;


typedef struct s_mini
{
	char			**cmd;
	t_put			*put;
	struct s_mini	*next;
}t_mini;

#endif
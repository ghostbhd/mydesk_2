/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:29:03 by abouhmad          #+#    #+#             */
/*   Updated: 2022/06/14 09:10:41 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_free(char **s, int i)
{
	while (i)
		free(s[i--]);
	free(s);
}

char	*ft_strndup(char *s1, int n)
{
	char	*str;
	int		i;
	int		len;

	len = ft_strlen(s1);
	str = malloc(n + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static int	ft_len(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_word(char *s, int wc, char c, int len)
{
	int		j;
	int		i;
	char	**p;

	j = 0;
	i = 0;
	p = malloc(sizeof(char *) * (wc + 1));
	if (!p)
		return (0);
	while (j < wc)
	{
		while (s[i] && s[i] == c)
			i++;
		len = ft_len(s + i, c);
		p[j] = ft_strndup(s + i, len);
		if (!p[j])
		{
			ft_free(p, j - 1);
			return (0);
		}
		i += len;
		j++;
	}
	p[wc] = NULL;
	return (p);
}

char	**ft_split(char *str, char c)
{
	char	**p;
	int		i;
	int		wc;
	int		h;

	if (!str)
		return (0);
	i = 0;
	wc = 0;
	while (str[i] == c && str[i])
		i++;
	h = i;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i + 1])
				i++;
			wc++;
		}
		i++;
	}
	p = ft_word((char *) str + h, wc, c, 0);
	return (p);
}

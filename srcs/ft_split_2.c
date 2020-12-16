/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:40:58 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/10 20:03:39 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		c_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		while (s[i] && s[i] != c)
			i++;
		count++;
	}
	return (count);
}

static int		size_words(char const *s, char c)
{
	int count;

	count = 0;
	while (*s != c && *s)
	{
		count++;
		s++;
	}
	return (count);
}

static	char	**m_free(char **p, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (p[i] != NULL)
		{
			free(p[i]);
			i++;
		}
	}
	free(p);
	return (NULL);
}

char			**ft_tab(char const *s, char **tab, char c, int j)
{
	int k;

	while (*s)
	{
		while ((*s == c) && *s)
			s++;
		if (*s)
		{
			k = 0;
			if (!(tab[j] = (char *)malloc(sizeof(char) *
							size_words(s, c) + 2)))
				return (m_free(&tab[j], size_words(s, c) + 1));
			while (*s && *s != c)
				tab[j][k++] = *(s++);
			if (tab[j][k] != '/')
				tab[j][k] = '/';
			tab[j++][k + 1] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_split_2(char const *s, char c)
{
	char	**tab;
	int		j;
	char	**str;

	j = 0;
	if (s == NULL ||
			!(tab = (char **)malloc(sizeof(char *) * (c_words(s, c) + 1))))
		return (NULL);
	str = ft_tab(s, tab, c, j);
	return (str);
}

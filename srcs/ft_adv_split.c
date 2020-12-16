/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adv_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:26:25 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/10 19:56:48 by amoujane         ###   ########.fr       */
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

char			**ft_adv_tab(char *s, char **tab, char c, int j)
{
	int k;

	k = 0;
	while (*s)
	{
		while ((*s == c) && *s)
			s++;
		if (*s)
		{
			k = 0;
			if (!(tab[j] = (char *)malloc(sizeof(char) *
							size_words(s, c) + 1)))
				return (m_free(&tab[j], size_words(s, c) + 1));
			while (*s && *s != c)
				tab[j][k++] = *(s++);
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_adv_split(char *s, char c)
{
	char	**tab;
	int		j;

	j = 0;
	if (s == NULL ||
			!(tab = (char **)malloc(sizeof(char *) * (c_words(s, c) + 1))))
		return (NULL);
	ft_change_char(s, c, 7);
	tab = ft_adv_tab(s, tab, c, j);
	ft_change_char_tab(tab, c);
	return (tab);
}

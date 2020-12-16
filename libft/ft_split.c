/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 21:01:32 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/13 13:01:48 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_get_table(char *str, char c)
{
	size_t	i;
	size_t	end;
	char	**tab;
	int		counter;

	counter = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		end = i;
		while (str[end] != c && str[end])
			end++;
		if (end > i)
		{
			counter++;
			i = end;
		}
		i++;
	}
	tab = (char**)malloc(sizeof(char*) * (counter + 1));
	if (!tab)
		return (NULL);
	return (tab);
}

static char		**ft_free(char **tab, int c_tab)
{
	int i;

	i = 0;
	while (i <= c_tab)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static char		**ft_return(char const *str, char **tab, char c)
{
	size_t	i;
	size_t	end;
	int		counter;

	i = 0;
	counter = 0;
	while (i < ft_strlen((char *)str))
	{
		end = i;
		while (str[end] != c && str[end])
			end++;
		if (end > i)
		{
			tab[counter] = (char*)malloc(sizeof(char) * (end - i + 1));
			if (!tab)
				return (ft_free(tab, counter));
			ft_strlcpy(tab[counter], (char *)&str[i], end - i + 1);
			counter++;
			i = end;
		}
		i++;
	}
	tab[counter] = NULL;
	return (tab);
}

char			**ft_split(char const *str, char c)
{
	char	**tab;
	char	*s;
	char	**nstr;

	if (!str)
		return (NULL);
	s = (char *)str;
	tab = ft_get_table(s, c);
	if (!tab)
		return (NULL);
	nstr = ft_return(str, tab, c);
	return (nstr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewrite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:40:56 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/10 19:08:35 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_rewirte_qq(char **str, char *first, char *mid, int i)
{
	char	*end;
	char	*s1;
	int		j;
	char	*t;

	end = NULL;
	s1 = NULL;
	t = *str;
	first = ft_strcut(*str, 0, i);
	i++;
	j = i;
	while (t[i] && (t[i] != '"' || (t[i] == '"' && t[i - 1] == '\\')))
		i++;
	mid = ft_strcut(*str, j, i - j);
	mid = ft_adresse(mid);
	end = ft_strcut(*str, i + 1, -1);
	s1 = *str;
	*str = ft_super_join(first, mid, end);
	free(s1);
	free(first);
	free(end);
	free(mid);
	i -= 2;
	return (i);
}

int		ft_rewirte_q(char **str, char *first, char *mid, int i)
{
	char	*end;
	char	*s1;
	int		j;
	char	*t;

	end = NULL;
	s1 = NULL;
	t = *str;
	first = ft_strcut(*str, 0, i);
	i++;
	j = i;
	while (t[i] && t[i] != '\'')
		i++;
	mid = ft_strcut(*str, j, i - j);
	end = ft_strcut(*str, i + 1, -1);
	s1 = *str;
	*str = ft_super_join(first, mid, end);
	free(s1);
	free(first);
	free(end);
	free(mid);
	i -= 2;
	return (i);
}

int		ft_rewrite_string(char **str, int i)
{
	int len;

	len = 0;
	len = ft_strlen(*str);
	*str = ft_adresse(*str);
	i += ft_strlen(*str) - len;
	return (i);
}

char	*ft_rewrite(char *str)
{
	int		i;
	char	*first;
	char	*mid;

	i = 0;
	first = NULL;
	mid = NULL;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '"' && str[i - 1] != '\\')
			i = ft_rewirte_qq(&str, first, mid, i);
		else if (str[i] == '\'')
			i = ft_rewirte_q(&str, first, mid, i);
		else if (str[i] == '$' && str[i - 1] != '\\' && \
		(ft_isalnum(str[i + 1]) || str[i + 1] == '?' \
		|| str[i + 1] == '\'' || str[i + 1] == '"'))
			i = ft_rewrite_string(&str, i);
		i++;
	}
	return (str);
}

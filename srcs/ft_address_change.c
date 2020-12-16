/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address_change.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:10:54 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/11 19:43:13 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		*ft_tab_fill(int i, int count, int start)
{
	int *tab;

	tab = (int *)malloc(sizeof(int) * 3);
	tab[0] = count;
	tab[1] = i;
	tab[2] = start;
	return (tab);
}

void	ft_ret_line(char **name, char **last, char **first, int *tab)
{
	*first = ft_strrejoin(g_tmp, 0, tab[2]);
	*name = ft_strrejoin(g_tmp, tab[2] + 1, tab[0]);
	*last = ft_strrejoin(g_tmp, tab[1], -1);
}

char	*ft_ret(char *name, char *first, char *last, int *num)
{
	char *p;
	char *ret;

	p = NULL;
	ret = NULL;
	if (ft_find_somthing2(name) != NULL)
		p = ft_find_somthing2(name);
	else
	{
		free(p);
		p = ft_strdup("");
	}
	*num = ft_strlen(p);
	ret = ft_join(first, p, last);
	return (ret);
}

char	*ft_addr(char *str, int start, int *num)
{
	int		i;
	int		test;
	int		count;
	int		*tab;
	char	*tab_str[4];

	count = 0;
	tab_str[0] = NULL;
	tab_str[1] = NULL;
	tab_str[2] = NULL;
	tab_str[3] = NULL;
	test = 0;
	i = start + 1;
	count = ft_valid_name(str, &i);
	tab = ft_tab_fill(i, count, start);
	ft_ret_line(&tab_str[2], &tab_str[1], &tab_str[0], tab);
	test = *num;
	tab_str[3] = ft_ret(tab_str[2], tab_str[0], tab_str[1], &test);
	*num = test;
	ft_free(tab_str[0], tab_str[1], tab_str[2]);
	return (tab_str[3]);
}

char	*ft_adresse(char *str)
{
	int		i;
	char	*s1;
	int		num;
	int		qt;

	i = 0;
	s1 = NULL;
	num = 0;
	qt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$' && str[i - 1] != '\\' && \
		(ft_isalnum(str[i + 1]) || str[i + 1] == '?' \
		|| str[i + 1] == '\'' || str[i + 1] == '"'))
		{
			s1 = str;
			g_tmp = str;
			str = ft_addr(str, i, &num);
			i += num;
			free(s1);
			i--;
		}
		i++;
	}
	return (str);
}

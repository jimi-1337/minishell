/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list_util_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:53:19 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/18 19:05:27 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	lstadd(t_upe **alst, char *key, char *value)
{
	t_upe *env;

	delkey(alst, key);
	env = lstnew(key, value);
	env->next = *alst;
	*alst = env;
	g_len_env++;
}

int		ft_str2dlen(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

size_t	ft_count_av(char *str)
{
	int i;

	i = 0;
	while (str[i] != '=')
		i++;
	return (i);
}

char	*ft_cpy_stop(char *s1, char c)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	i = 0;
	str = malloc(ft_count_av(s1) + 1);
	while (s1[i] && s1[i] != c)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_cpy_after(char *s1, char c)
{
	int		i;
	int		len;
	char	*str;
	int		x;

	(void)c;
	len = ft_strlen(s1) - ft_count_av(s1);
	str = malloc(len + 1);
	i = ft_count_av(s1) + 1;
	x = ft_count_av(s1) + 1;
	while (s1[i])
	{
		str[i - x] = s1[i];
		i++;
	}
	str[i - x] = '\0';
	return (str);
}

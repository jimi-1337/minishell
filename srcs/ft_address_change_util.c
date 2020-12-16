/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address_change_util.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:31:44 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/11 19:43:33 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_join(char *s1, char *s2, char *s3)
{
	char	*ret;
	int		i;
	int		j;

	i = -1;
	j = 0;
	ret = (char*)malloc(sizeof(char) * \
	(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1));
	while (s1[++i] != '\0')
		ret[i] = s1[i];
	while (s2[j] != '\0')
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	j = 0;
	while (s3[j] != '\0')
	{
		ret[i] = s3[j];
		j++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strrejoin(char *str, int start, int len)
{
	char	*s;
	int		num;
	int		i;

	num = 0;
	i = 0;
	if (len < 0)
		len = ft_strlen(str) - start;
	s = (char*)malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		s[i] = str[start];
		start++;
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_find_somthing2(char *str)
{
	t_upe	*tmp;
	char	*home;

	tmp = g_env_v;
	if (!ft_strcmp(str, "?"))
		return (ft_itoa(g_rep_g_fail));
	while (ft_strcmp(tmp->key, str) && tmp->next)
	{
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		return (NULL);
	else
		home = tmp->value;
	return (home);
}

int		ft_valid_name(char *str, int *i)
{
	int count;

	count = 0;
	while ((str[*i] >= 48 && str[*i] <= 57) \
	|| (str[*i] >= 65 && str[*i] <= 90) || (str[*i] >= 97 && str[*i] <= 122) \
	|| str[*i] == '_' || str[*i] == '?')
	{
		count++;
		*i = *i + 1;
	}
	return (count);
}

void	ft_free(char *first, char *last, char *name)
{
	free(first);
	free(last);
	free(name);
}

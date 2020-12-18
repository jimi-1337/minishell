/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:45:08 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/18 19:25:00 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_isalnum_(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	if (c >= 65 && c <= 90)
		return (1);
	if (c >= 97 && c <= 122)
		return (1);
	if (c == '_')
		return (1);
	return (0);
}

int		ft_key_valid(char *str)
{
	int i;

	i = 0;
	if ((str[0] >= 'a' && str[0] <= 'z') \
	|| (str[0] >= 'A' && str[0] <= 'Z') || str[0] == '_')
	{
		while (str[i])
		{
			if (!ft_isalnum_(str[i]))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int		ft_check_key(char *str)
{
	t_upe	*tmp;
	char	*cmp;

	tmp = g_declare;
	cmp = ft_strdup("a");
	cmp[0] = 7;
	if (!tmp)
		return (1);
	while (ft_strcmp(tmp->key, str) && tmp->next)
		tmp = tmp->next;
	if (tmp->next != NULL)
	{
		if (!ft_strcmp(tmp->value, cmp))
		{
			ft_memdel(cmp);
			return (1);
		}
		ft_memdel(cmp);
		return (0);
	}
	else
		return (1);
	return (0);
}

void	ft_get_key_value(char *str, char **key, char **value, int j)
{
	*key = ft_substr(str, 0, j);
	*value = ft_substr(str, j + 1, ft_strlen(str) - j);
}

void	ft_add(char *key, char *value)
{
	lstadd(&g_env_v, key, value);
	lstadd_declare(&g_declare, key, value);
}

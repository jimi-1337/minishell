/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:01:11 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/10 20:05:24 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print(char *str)
{
	g_fail = 1;
	ft_putstr("bash: export: `");
	ft_putstr(str);
	ft_putstr("': not a valid identifier\n");
}

char	*ft_fill_tmp(void)
{
	char *tmp;

	tmp = NULL;
	tmp = ft_strdup("a");
	tmp[0] = 7;
	return (tmp);
}

int		ft_export_line(char *str)
{
	int		j;
	char	*key;
	char	*value;
	char	*tmp;

	j = 0;
	key = NULL;
	value = NULL;
	tmp = ft_fill_tmp();
	j = ft_return_j(str, j);
	if (str[j] == '=')
	{
		ft_get_key_value(str, &key, &value, j);
		(ft_key_valid(key)) ? ft_add(key, value) : ft_print(str);
		if (ft_key_valid(key))
			return (0);
	}
	else
	{
		(!ft_key_valid(str)) ? ft_print(str) : 1;
		if (ft_key_valid(str))
			(ft_check_key(str)) ? lstadd_declare(&g_declare, str, tmp) : 1;
	}
	ft_memdel(tmp);
	return (1);
}

void	ft_declare(void)
{
	int		i;
	t_upe	*tmp;
	char	*cmp;

	i = 0;
	tmp = g_declare;
	cmp = ft_strdup("a");
	cmp[0] = 7;
	while (i < g_len_declare && tmp)
	{
		ft_putstr("declare -x ");
		ft_putstr(tmp->key);
		if (tmp->value && ft_strcmp(tmp->value, cmp))
		{
			ft_putstr("=");
			ft_putstr("\"");
			ft_putstr(tmp->value);
			ft_putstr("\"");
		}
		ft_putstr("\n");
		tmp = tmp->next;
		i++;
	}
	ft_memdel(cmp);
}

void	ft_export(char **str)
{
	int i;
	int x;
	int y;

	g_fail = 0;
	i = 1;
	x = 0;
	y = 0;
	if (str[1] == NULL)
	{
		ft_declare();
		return ;
	}
	while (str[i] != NULL)
	{
		x = ft_export_line(str[i]);
		if (y == 0 && x != 0)
			y = x;
		i++;
	}
	if (g_indice == 1 && g_fail == 0 && y == 0)
		exit(0);
	else if (g_indice == 1 && g_fail && y)
		exit(1);
}

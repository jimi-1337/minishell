/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adv_split_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:32:25 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/10 16:59:58 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_change_handle_q(char **str, char change, char to, int i)
{
	char *tmp;

	tmp = *str;
	i++;
	while (tmp[i] && tmp[i] != '\'')
	{
		if (tmp[i] == change)
			tmp[i] = to;
		i++;
	}
	return (i);
}

int		ft_change_handle_qq(char **str, char change, char to, int i)
{
	char *tmp;

	tmp = *str;
	i++;
	while (tmp[i] && (tmp[i] != '"' || (tmp[i] == '"' && tmp[i - 1] == '\\')))
	{
		if (tmp[i] == change)
			tmp[i] = to;
		i++;
	}
	return (i);
}

void	ft_change_char(char *str, char change, char to)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		if (str[i] == '\'')
			i = ft_change_handle_q(&str, change, to, i);
		else if (str[i] && str[i] == '"' && str[i - 1] != '\\')
			i = ft_change_handle_qq(&str, change, to, i);
		i++;
	}
}

void	ft_change_char_tab(char **tab, char c)
{
	int i;

	i = 0;
	if (tab[i] == NULL)
		return ;
	while (tab[i] != NULL)
	{
		ft_change_char(tab[i], 7, c);
		i++;
	}
}

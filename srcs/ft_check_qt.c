/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_qt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:31:38 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/10 17:06:09 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_handle_quot(char *str, int i)
{
	while (str[i] != '\0' && (str[i] != '"' \
	|| (str[i] == '"' && str[i - 1] == '\\')))
		i++;
	return (i);
}

int		ft_check_qt(char *str)
{
	int i;
	int t;

	t = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"' && str[i - 1] != '\\')
		{
			i++;
			i = ft_handle_quot(str, i);
			if (str[i] != '"')
				return (1);
		}
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\0' && str[i] != '\'')
				i++;
			if (str[i] != '\'')
				return (1);
		}
		i++;
	}
	return (0);
}

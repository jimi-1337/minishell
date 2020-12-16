/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:11:49 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/12 12:49:07 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int		shell(char **str)
{
	int ret;

	g_fail ? ft_putstr_fd("🤬 ", 2) : ft_putstr_fd("😎 ", 2);
	ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd(g_path.pwd, 2);
	ft_putstr_fd("-->", 2);
	ft_putstr_fd("\033[0m", 2);
	ret = get_next_line(0, str);
	return (ret);
}

char	**ft_rewrite_d(char **str)
{
	int		i;
	char	**new;
	int		x;

	i = 0;
	x = ft_strlenn(str);
	new = (char **)malloc(sizeof(char *) * (x + 1));
	while (str[i] != NULL)
	{
		new[i] = ft_rewrite(str[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

int		ft_return_j(char *str, int j)
{
	while (str[j] && str[j] != '=')
		j++;
	return (j);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:44:09 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/16 19:15:38 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_echo_print(char **str, int i, int newline)
{
	int		j;

	while (str[i] && str[i][0] == '-')
	{
		if (str[i][1] == 'n')
		{
			j = 2;
			while (str[i][j] && str[i][j] == 'n')
				j++;
			if (str[i][j] == '\0')
				newline = 1;
			else
				break ;
		}
		else
			break ;
		i++;
	}
	while (str[i] != NULL)
	{
		ft_putstr(str[i]);
		(str[i + 1] != NULL) ? ft_putchar(' ') : 1;
		i++;
	}
	return (newline);
}

void	ft_echo(char **str)
{
	int i;
	int newline;

	g_fail = 0;
	newline = 0;
	i = 1;
	if (!str[1])
	{
		ft_putstr("\n");
		exit(0);
	}
	if ((newline = ft_echo_print(str, i, newline)) == 0)
		write(1, "\n", 1);
	exit(0);
}

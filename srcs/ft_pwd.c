/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:48:19 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/11 17:40:11 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_pwd(char *buff, int x, char *dir, int i)
{
	while (i < 3)
	{
		dir = getcwd(buff, x);
		if (dir == NULL)
			i++;
		else if ((int)ft_strlen(dir) == x)
		{
			x = (x * 2);
			i++;
		}
		else
			break ;
	}
	return (dir);
}

void	ft_pwd(void)
{
	char	*buff;
	char	*dir;
	int		x;
	int		i;

	x = 4091;
	buff = NULL;
	dir = NULL;
	g_fail = 0;
	i = 0;
	if (g_path.pwd)
	{
		ft_putstr(g_path.pwd);
		ft_putchar('\n');
		exit(0);
	}
	else if ((dir = ft_get_pwd(buff, x, dir, i)) != NULL)
	{
		ft_putstr(dir);
		ft_putchar('\n');
		exit(0);
	}
	exit(1);
}

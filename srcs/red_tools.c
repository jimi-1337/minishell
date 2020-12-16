/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:29:42 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/16 16:07:22 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_error_print(char *str)
{
	ft_putstr_fd(str, 2);
	g_fail = 127;
	g_red_fail = 1;
	return (1);
}

void	ft_free_double(char **str)
{
	int i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
}

int		ft_skip_q(char *str, char type)
{
	int i;

	i = 0;
	while (str[i] != type)
		i++;
	return (i + 1);
}

int		ft_create_file(char *file)
{
	int fd;

	file = ft_rewrite(file);
	fd = open(file, O_CREAT, 0666);
	close(fd);
	return (0);
}

int		ft_check_file(char *file)
{
	int		fd;
	char	*tmp;

	fd = -1;
	tmp = ft_rewrite(file);
	fd = open(tmp, O_RDONLY);
	close(fd);
	free(tmp);
	if (fd < 0)
		return (0);
	return (1);
}

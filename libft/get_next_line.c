/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:39:25 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/12 13:20:25 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ret_gnl(int fd, char **tab)
{
	char *temp;

	temp = NULL;
	temp = tab[fd];
	tab[fd] = NULL;
	free(temp);
	write(1, "exit\n", 5);
	return (0);
}

int		return_f(char **tab, int n, char **line, int fd)
{
	char	*temp;
	int		i;

	i = 0;
	while (tab[fd][i] && tab[fd][i] != '\n')
		i++;
	*line = ft_strsub(tab[fd], 0, i);
	if (!tab[fd][i])
		return (ft_ret_gnl(fd, tab));
	else
	{
		temp = tab[fd];
		tab[fd] = ft_strdup((tab[fd]) + i + 1);
		free(temp);
	}
	if (!tab[fd] || !*line)
		return (-1);
	if (n || (n == 0 && tab[fd] != NULL))
		return (1);
	return (-1);
}

int		ft_ctrl_d(void)
{
	write(2, "yy", 2);
	write(2, "\b\b  \b\b \b\b", 8);
	return (0);
}

char	*ft_tmp_ret(char **tab, int fd, int n, char *buf)
{
	char	*temp;

	(buf[n + 1] != '\0' || n == 0) ? ft_ctrl_d() : 1;
	temp = tab[fd];
	buf[n] = '\0';
	return (temp);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*tab[4864];
	char		*temp;
	int			n;

	buf = NULL;
	if (!line || fd < 0 || fd >= 4864 || BUFFER_SIZE <= 0
			|| !(buf = malloc(BUFFER_SIZE + 1)) || read(fd, buf, 0) == -1)
		return (-1);
	if (!tab[fd] && !(tab[fd] = ft_strdup("")))
		return (-1);
	while ((n = read(fd, buf, BUFFER_SIZE)) > 0 ||
			(n == 0 && ft_strlen(tab[fd]) != 0))
	{
		temp = ft_tmp_ret(tab, fd, n, buf);
		if (!(tab[fd] = ft_strjoin(tab[fd], buf)))
			return (-1);
		free(temp);
		if (ft_strchr(tab[fd], '\n') != 0)
			break ;
	}
	free(buf);
	if (n < 0)
		return (-1);
	return (return_f(tab, n, line, fd));
}

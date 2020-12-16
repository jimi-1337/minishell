/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:59:09 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/11 20:41:40 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_replace(char *str)
{
	ft_red_fun(str);
}

void	ft_fork_p(int fds, char *s1, int *fd)
{
	int id;

	pipe(fd);
	id = fork();
	if (id != 0)
	{
		if (fds != -1)
			close(fds);
		close(fd[1]);
	}
	else
	{
		if (fds != -1)
		{
			dup2(fds, 0);
			close(fds);
		}
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		ft_replace(s1);
	}
}

int		ft_pipe(int fds, char *s1)
{
	int fd[2];

	ft_fork_p(fds, s1, fd);
	g_f = 0;
	return (fd[0]);
}

int		ft_fork_pf(int fds, char *s1)
{
	int status;
	int id;

	status = 0;
	id = fork();
	if (id != 0)
	{
		if (fds != -1)
			close(fds);
		waitpid(id, &status, 0);
		g_fail = WEXITSTATUS(status);
		while (waitpid(0, &status, 0) > 0)
		{
		}
	}
	else
	{
		if (fds != -1)
		{
			dup2(fds, 0);
			close(fds);
		}
		ft_replace(s1);
	}
	return (status);
}

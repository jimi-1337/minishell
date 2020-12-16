/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 19:49:32 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/16 19:53:51 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit_util(char **new)
{
	int i;

	i = ft_atoi(new[1]);
	if (i < 0 && new[1][0] != '-')
	{
		ft_putstr_fd("bash: exit: numeric argument required\n", 2);
		exit(2);
	}
	else if (i >= 0 && new[1][0] == '-')
	{
		ft_putstr_fd("bash: exit: numeric argument required\n", 2);
		exit(2);
	}
	exit(i);
}

void	ft_execute_path_tool(char *str, DIR *dir)
{
	closedir(dir);
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": is a directory\n", 2);
	exit(126);
}

void	ft_check(char **str, char *tmp, DIR *dir)
{
	tmp = ft_strjoin(tmp, "/");
	dir = opendir(tmp);
	free(tmp);
	if (dir != NULL)
		ft_execute_path_tool(str[0], dir);
	else if (dir == NULL)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(str[0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(127);
	}
	g_fail = 127;
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(str[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	if (g_f == 1)
	{
		g_indice = 0;
		exit(127);
	}
}

void	ft_exec_point(char **str, char **env)
{
	char	*tmp;
	char	*buff;
	DIR		*dir;

	tmp = NULL;
	buff = NULL;
	dir = NULL;
	if (str[0][1] == '.')
	{
		chdir("..");
		tmp = ft_strjoin(getcwd(buff, 1024), &str[0][2]);
		chdir(g_path.pwd);
	}
	else if (str[0][1] != '.')
		tmp = ft_strjoin(g_path.pwd, &str[0][1]);
	execve(tmp, str, env);
	free(tmp);
	ft_check(str, tmp, dir);
}

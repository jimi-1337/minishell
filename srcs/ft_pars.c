/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:24:52 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/18 17:40:11 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_execute_path_after(char **str, char **env)
{
	char	*tmp;
	DIR		*dir;

	execve(str[0], str, env);
	tmp = ft_strjoin(str[0], "/");
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
}

void	ft_execute_path(char **str, char **env)
{
	DIR				*dir;
	struct dirent	*dp;
	char			*tmp;
	char			*buff;

	dir = NULL;
	tmp = NULL;
	dp = NULL;
	buff = NULL;
	if (str[0][0] == '.')
		ft_exec_point(str, env);
	else if (str[0][0] == '/')
		ft_execute_path_after(str, env);
}

int		ft_execut_cmd(char **str, char **env, int x)
{
	char	**path;
	char	*tmp;

	path = NULL;
	g_path_len = 0;
	tmp = NULL;
	path = ft_find_path();
	g_path_len = ft_str2dlen(path);
	while (path[x])
	{
		tmp = ft_strjoin(path[x], str[0]);
		execve(tmp, str, env);
		free(tmp);
		x++;
	}
	return (x);
}

void	ft_execut_or_exit(int x, char **str, char **env)
{
	if (x == g_path_len)
	{
		execve(str[0], str, env);
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
}

void	ft_cmd(char **str)
{
	int		x;
	char	**env;

	x = 0;
	g_indice = 0;
	g_fail = 0;
	g_path_len = 0;
	env = NULL;
	env = ft_environ(g_env_v);
	if (env == NULL || env[0] == NULL)
	{
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
	ft_execute_path(str, env);
	x = ft_execut_cmd(str, env, x);
	ft_execut_or_exit(x, str, env);
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 19:10:45 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/10 19:20:38 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_pipe_fin(int fds, char *s1)
{
	int status;

	status = ft_fork_pf(fds, s1);
	if (status && g_fail == 0)
	{
		if (status == 3)
			g_fail = 131;
		if (status == 2)
			g_fail = 130;
	}
	g_f = 0;
	return (g_fail);
}

int		ft_whitespaces(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' \
				|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
	{
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

int		ft_error_pipe(char **tmp)
{
	int i;

	i = 0;
	while (tmp[i] != NULL)
	{
		if (ft_whitespaces(tmp[i]))
		{
			g_fail = 258;
			ft_putstr_fd("bash: syntax error near unexpected token `|'\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_building_fun(char *str)
{
	char **cmd;

	cmd = NULL;
	g_f = 0;
	g_indice = 0;
	cmd = ft_adv_split(str, ' ');
	if (cmd[0] == NULL)
		return (1);
	cmd[0] = ft_rewrite(cmd[0]);
	if ((ft_strcmp(ft_lowstring(cmd[0]), "exit") == 0) || \
			(ft_strcmp(ft_lowstring(cmd[0]), "cd") == 0) \
			|| (ft_strcmp(ft_lowstring(cmd[0]), "export") == 0) \
			|| (ft_strcmp(ft_lowstring(cmd[0]), "unset") == 0))
	{
		ft_replace(str);
		return (1);
	}
	ft_free_double(cmd);
	return (0);
}

void	ft_pipe_fun(char *str)
{
	char	**tmp;
	int		i;
	int		fds;

	fds = -1;
	tmp = ft_adv_split(str, '|');
	if (ft_error_pipe(tmp) == 1)
		return ;
	if (tmp[1] == NULL && ft_building_fun(str) == 1)
		return ;
	i = 0;
	while (tmp[i] != NULL)
	{
		g_fail = 0;
		g_indice = 1;
		g_f = 1;
		if (tmp[i + 1] != NULL)
			fds = ft_pipe(fds, tmp[i]);
		else
			ft_pipe_fin(fds, tmp[i]);
		i++;
	}
	ft_free_double(tmp);
}

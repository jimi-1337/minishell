/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:08:55 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/11 20:46:05 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pass_line(char **tmp, int i)
{
	while (tmp[i] != NULL)
	{
		if (!ft_check_qt(tmp[i]) && !ft_check_slash(tmp[i]))
		{
			ft_white_space_fix(tmp[i]);
			ft_pipe_fun(tmp[i]);
		}
		else
		{
			free(tmp[i]);
			tmp[i] = NULL;
			ft_putstr("error multiline\n");
			g_fail = 127;
		}
		i++;
	}
}

void	ft_check_get_next_line(char *str, int x)
{
	if (x < 0)
	{
		g_fail = 127;
		free(str);
		str = NULL;
		ft_putstr("something went wrong with the line\n");
		exit(1);
	}
}

void	ft_norm(char *str, int i, int error)
{
	char **tmp;

	tmp = NULL;
	tmp = ft_adv_split(str, ';');
	i = ft_check_line(tmp, error);
	ft_pass_line(tmp, i);
	ft_free_double(tmp);
}

void	run_shell(void)
{
	int		x;
	char	*str;
	int		i;
	int		error;

	x = 1;
	str = NULL;
	i = 0;
	init_cache();
	while (x > 0)
	{
		error = 0;
		g_rep_g_fail = g_fail;
		x = shell(&str);
		g_str = str;
		ft_check_get_next_line(str, x);
		if (str != NULL && !ft_check_start(str))
			ft_norm(str, i, error);
		ft_memdel(str);
	}
	ft_free_struct(g_env_v);
	ft_putstr("exit\n");
}

int		main(void)
{
	signal(SIGINT, ft_ctrl_c);
	signal(SIGQUIT, ft_ctrl_bslash);
	run_shell();
	exit(0);
	return (0);
}

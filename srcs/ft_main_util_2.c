/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_util_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:49:15 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/18 17:35:31 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_lowstring(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

void	ft_exit(char **new)
{
	long long i;

	i = 0;
	ft_putstr("exit\n");
	g_indice = 0;
	if (new[1] != NULL)
	{
		while (new[1][i] != '\0')
		{
			if (new[1][i] >= 0 && new[1][i] <= '9')
				i++;
			else
			{
				ft_putstr_fd("bash: exit: numeric argument required\n", 2);
				break ;
			}
		}
		ft_exit_util(new);
	}
	exit(0);
}

void	ft_opts(char *str)
{
	char	**tmp;
	char	**new;

	tmp = NULL;
	new = NULL;
	tmp = ft_adv_split(str, ' ');
	new = ft_rewrite_d(tmp);
	if (ft_strcmp(ft_lowstring(new[0]), "exit") == 0)
		ft_exit(new);
	else if (ft_strcmp(ft_lowstring(new[0]), "echo") == 0)
		ft_echo(new);
	else if (ft_strcmp(ft_lowstring(new[0]), "cd") == 0)
		ft_cd(new);
	else if (ft_strcmp(ft_lowstring(new[0]), "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(ft_lowstring(new[0]), "export") == 0)
		ft_export(new);
	else if (ft_strcmp(ft_lowstring(new[0]), "unset") == 0)
		ft_unset(new);
	else if ((ft_strcmp(ft_lowstring(new[0]), "env") == 0) && (new[1] == NULL))
		ft_env();
	else if (new[0] != '\0')
		ft_cmd(new);
}

void	init_cache(void)
{
	char	*dir;
	int		x;
	char	*buff;

	x = 1000;
	dir = NULL;
	buff = NULL;
	dir = getcwd(buff, x);
	g_len_env = 0;
	g_path.pwd = dir;
	g_out = dup(1);
	g_in = dup(0);
	g_red.in = g_in;
	g_red.out = g_out;
	g_fail = 0;
	g_red.cmd = NULL;
	g_f = 0;
	g_rep_g_fail = 0;
	g_red.arg = ft_strdup("");
	ft_env_init(buff);
}

int		ft_check_slash(char *str)
{
	int i;
	int start;

	i = 0;
	if (str == NULL)
		return (1);
	i = ft_strlen(str) - 1;
	start = i;
	while (i > 0 && (str[i] == ' ' || str[i] == '\t' \
	|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
	{
		i--;
	}
	if ((str[i] == '\\' && str[i - 1] != '\\') || str[i] == '>' \
	|| str[i] == '|' || str[i] == '<')
		return (1);
	return (0);
}

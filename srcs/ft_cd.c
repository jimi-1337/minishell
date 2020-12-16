/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:34:28 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/11 17:22:10 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd_home(char *tmp, int *x)
{
	tmp = g_path.oldpwd;
	ft_old_pwd();
	g_path.home = ft_find_somthing("HOME");
	if (g_path.home != NULL)
		*x = chdir(g_path.home);
	else
	{
		g_fail = 1;
		ft_putstr_fd("bash: cd: HOME not set\n", 2);
		if (g_indice == 1)
			exit(1);
	}
	ft_newpwd();
	if (!ft_strcmp(g_path.pwd, g_path.oldpwd))
		g_path.oldpwd = tmp;
	if (g_indice == 1 && x >= 0)
		exit(0);
}

void	ft_cd_old(int *x)
{
	if (g_path.oldpwd)
	{
		*x = chdir(g_path.oldpwd);
		ft_putstr(g_path.oldpwd);
		ft_putchar('\n');
		g_path.oldpwd = g_path.pwd;
		lstadd(&g_env_v, "OLDPWD", g_path.oldpwd);
		ft_newpwd();
	}
	else
	{
		g_fail = 1;
		ft_putstr_fd("bash: cd: OLDPWD not set\n", 2);
		if (g_indice == 1)
			exit(1);
	}
	if (g_indice == 1 && x >= 0)
		exit(0);
}

void	ft_cd_str(char *tmp, char *str, int *x)
{
	tmp = g_path.oldpwd;
	ft_old_pwd();
	*x = chdir(str);
	ft_newpwd();
	if (!ft_strcmp(g_path.pwd, g_path.oldpwd))
		g_path.oldpwd = tmp;
	if (g_indice == 1 && *x >= 0)
		exit(0);
}

void	ft_cd(char **str)
{
	int		i;
	int		x;
	char	*tmp;

	g_fail = 0;
	i = 0;
	x = 0;
	tmp = NULL;
	if (str[1] == NULL || (ft_strcmp(str[1], "~") == 0))
		ft_cd_home(tmp, &x);
	else if (ft_strcmp(str[1], "-") == 0)
		ft_cd_old(&x);
	else if (str[1])
		ft_cd_str(tmp, str[1], &x);
	if (x < 0)
	{
		g_fail = 1;
		ft_putstr_fd("bash: cd:", 2);
		ft_putstr_fd(str[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		if (g_indice == 1)
			exit(1);
		return ;
	}
}

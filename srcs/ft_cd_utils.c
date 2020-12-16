/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:28:56 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/11 17:38:55 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_old_pwd(void)
{
	char	*dir;
	int		x;
	char	*buff;

	dir = NULL;
	x = 4091;
	buff = NULL;
	dir = getcwd(buff, x);
	(dir != NULL) ? (g_path.oldpwd = dir) : (char *)1;
	lstadd(&g_env_v, "OLDPWD", g_path.oldpwd);
}

void	ft_newpwd(void)
{
	char	*dir;
	int		x;
	char	*buff;

	x = 4091;
	dir = NULL;
	buff = NULL;
	dir = getcwd(buff, x);
	if (dir == NULL)
	{
		ft_putstr_fd("cd: error retrieving current directory: getcwd:", 2);
		ft_putstr_fd("cannot access parent directories:", 2);
		ft_putstr_fd(" No such file or directory\n", 2);
		return ;
	}
	g_path.pwd = dir;
	lstadd(&g_env_v, "PWD", dir);
}

char	*ft_find_somthing(char *str)
{
	t_upe	*tmp;
	char	*home;

	tmp = g_env_v;
	if (g_env_v == NULL)
		return (NULL);
	while (ft_strcmp(tmp->key, str) && tmp->next)
	{
		tmp = tmp->next;
	}
	if (tmp->next != NULL)
		home = tmp->value;
	else
		home = NULL;
	return (home);
}

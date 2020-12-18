/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:48:18 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/18 17:39:40 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_add_env(char *environ, char **s1, char **s2)
{
	*s1 = ft_cpy_stop(environ, '=');
	*s2 = ft_cpy_after(environ, '=');
	lstadd(&g_env_v, *s1, *s2);
	lstadd_declare(&g_declare, *s1, *s2);
	ft_memdel(*s1);
	ft_memdel(*s2);
}

void	ft_env_init(char *buff)
{
	extern char		**environ;
	int				i;
	char			*s1;
	char			*s2;

	i = 0;
	s1 = NULL;
	s2 = NULL;
	g_env_v = lstnew("TERM", "xterm-256color");
	g_declare = lstnew("TERM", "xterm-256color");
	g_len_env = 1;
	g_len_declare = 1;
	if (!environ || !environ[0])
	{
		lstadd(&g_env_v, "PWD", getcwd(buff, 4091));
		lstadd_declare(&g_declare, "PWD", getcwd(buff, 4091));
		return ;
	}
	while (environ[i] != NULL)
	{
		ft_add_env(environ[i], &s1, &s2);
		i++;
	}
}

char	**ft_find_path(void)
{
	t_upe	*tmp;
	char	**path;

	tmp = g_env_v;
	while (ft_strcmp(tmp->key, "PATH") && tmp->next)
	{
		tmp = tmp->next;
	}
	path = ft_split_2(tmp->value, ':');
	return (path);
}

char	**ft_environ(t_upe *env)
{
	t_upe	*tmp;
	char	**str;
	int		i;

	i = 0;
	tmp = env;
	str = (char **)malloc(sizeof(char *) * g_len_env + 1);
	while (i < g_len_env)
	{
		if (tmp)
		{
			str[i] = ft_super_join(tmp->key, "=", tmp->value);
			tmp = tmp->next;
			i++;
		}
		else
			break ;
	}
	str[i] = NULL;
	return (str);
}

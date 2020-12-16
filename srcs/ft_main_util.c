/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:44:49 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/10 18:34:44 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_memdel(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}

int		ft_white_space_fix(char *s)
{
	int		i;
	char	c;

	i = -1;
	c = ' ';
	while (s[++i] != '\0')
	{
		if (s[i] == '"' && s[i - 1] != '\\')
		{
			i++;
			while (s[i] != '\0' && (s[i] != '"' \
			|| (s[i] == '"' && s[i - 1] == '\\')))
				i++;
		}
		else if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\0' && s[i] != '\'')
				i++;
		}
		else if (s[i] == '\t' || s[i] == '\n' \
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
			s[i] = c;
	}
	return (0);
}

int		ft_check_start(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' \
	|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
	{
		i++;
	}
	if (str[i] == '|')
	{
		ft_putstr_fd("bash: syntax error near unexpected token `|'\n", 2);
		g_fail = 258;
		g_rep_g_fail = 258;
		return (1);
	}
	if (str[i] == ';')
	{
		ft_putstr_fd("bash: syntax error near unexpected token `;'\n", 2);
		g_fail = 258;
		g_rep_g_fail = 258;
		return (1);
	}
	return (0);
}

void	ft_free_struct(t_upe *env)
{
	while (env)
	{
		ft_memdel(env->key);
		ft_memdel(env->value);
		env = env->next;
	}
}

int		ft_check_line(char **str, int error)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		if (ft_whitespaces(str[i]) && error == 0)
		{
			error = 1;
			g_fail = 258;
			ft_putstr_fd("bash: syntax error near unexpected token `;'\n", 2);
		}
		i++;
	}
	if (error == 0)
		i = 0;
	return (i);
}

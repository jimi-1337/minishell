/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:29:35 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/10 19:03:24 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_red_in(char *str, int start)
{
	int		i;
	char	*tmp;
	char	**cmd;
	char	*in;

	tmp = NULL;
	in = NULL;
	cmd = NULL;
	if (g_red.cmd == NULL)
		g_red.cmd = ft_strcut(str, 0, start - 1);
	i = start;
	while (str[i] != '\0' && str[i] != '<' && str[i] != '>')
		i++;
	tmp = ft_strcut(str, start, i - start);
	cmd = ft_split(tmp, ' ');
	ft_check_file_get_cmd_in(cmd, &in);
	free(cmd);
	free(tmp);
	return (i - start);
}

void	ft_str_is_in(void)
{
	char *tmp;

	tmp = NULL;
	if (g_red.in != g_in)
	{
		dup2(g_red.in, 0);
		close(g_red.in);
	}
	if (g_red.out != g_out)
	{
		dup2(g_red.out, 1);
		close(g_red.out);
	}
	tmp = ft_super_join(g_red.cmd, " ", g_red.arg);
	ft_opts(tmp);
	free(tmp);
	tmp = NULL;
	dup2(g_in, 0);
	dup2(g_out, 1);
}

void	ft_handle_red(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
			i += ft_skip_q(&str[i + 1], '"');
		else if (str[i] == '\'')
			i += ft_skip_q(&str[i + 1], '\'');
		else if (str[i] == '>')
			i += ft_red_out(str, i + 1);
		else if (str[i] == '<')
			i += ft_red_in(str, i + 1);
		i++;
	}
}

void	ft_red_fun(char *str)
{
	g_red_fail = 0;
	ft_handle_red(str);
	if (g_red_fail != 0)
	{
		if (g_indice == 0)
			return ;
		if (g_indice == 1)
			exit(-5);
	}
	if (g_red.cmd == NULL)
		ft_opts(str);
	else
	{
		ft_str_is_in();
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red_fun_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:57:11 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/10 19:05:13 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_args_add(char **cmd)
{
	int		i;
	char	*tmp;

	i = 1;
	tmp = NULL;
	if (cmd[i] == NULL)
		return ;
	while (cmd[i] != NULL)
	{
		tmp = g_red.arg;
		g_red.arg = ft_super_join(g_red.arg, " ", cmd[i]);
		free(tmp);
		i++;
	}
}

void	ft_getfile_out(char **cmd, char **out, int ap, int start)
{
	ft_create_file(cmd[0]);
	ft_args_add(cmd);
	if (g_red.out != g_out)
		close(g_red.out);
	*out = ft_rewrite(cmd[0]);
	if (ap != start)
		g_red.out = open(*out, O_APPEND | O_WRONLY);
	else
		g_red.out = open(*out, O_WRONLY | O_TRUNC);
}

int		ft_get_cmd_out(char *str, int start, int *ap)
{
	int i;

	i = start;
	if (g_red.cmd == NULL)
		g_red.cmd = ft_strcut(str, 0, start - 1);
	if (str[i] == '>')
		i++;
	*ap = i;
	while (str[i] != '\0' && str[i] != '<' && str[i] != '>')
		i++;
	return (i);
}

int		ft_red_out(char *str, int start)
{
	int		i;
	char	*tmp;
	char	**cmd;
	int		ap;
	char	*out;

	tmp = NULL;
	ap = 0;
	cmd = NULL;
	out = NULL;
	if ((i = ft_get_cmd_out(str, start, &ap)) == ap)
		return (1);
	tmp = ft_strcut(str, ap, i - ap);
	cmd = ft_adv_split(tmp, ' ');
	ft_getfile_out(cmd, &out, ap, start);
	ft_free_double(cmd);
	free(tmp);
	return (i - start);
}

void	ft_check_file_get_cmd_in(char **cmd, char **in)
{
	if (ft_check_file(cmd[0]))
	{
		if (g_red.in != g_in)
			close(g_red.in);
		*in = ft_rewrite(cmd[0]);
		g_red.in = open(*in, O_RDONLY);
		ft_args_add(cmd);
	}
	else
	{
		if (cmd[0] == '\0')
			ft_error_print("bash: syntax error near unexpected token `<'\n");
		else
			ft_error_print("Error file doesn't exist\n");
	}
}

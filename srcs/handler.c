/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 22:32:34 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/13 14:12:56 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_ctrl_c(int nb)
{
	g_fail = 1;
	g_rep_g_fail = 1;
	(void)nb;
	if (g_f == 0)
	{
		ft_putstr_fd("\b\b  ", 1);
		ft_putstr_fd("\n", 1);
		g_fail ? ft_putstr_fd("🤬 ", 2) : ft_putstr_fd("😎 ", 2);
		ft_putstr_fd("\033[0;31m", 2);
		ft_putstr_fd(g_path.pwd, 2);
		ft_putstr_fd("-->", 2);
		ft_putstr_fd("\033[0m", 2);
		g_fail = 0;
	}
	else
	{
		g_fail = 130;
		g_rep_g_fail = 130;
	}
}

char	*ft_fix_gstr(void)
{
	char **cmd;

	cmd = NULL;
	if (g_str == NULL)
		return (NULL);
	ft_white_space_fix(g_str);
	cmd = ft_adv_split(g_str, ' ');
	cmd[0] = ft_rewrite(cmd[0]);
	return (cmd[0]);
}

void	ft_ctrl_bslash(int nb)
{
	char	*nbr;

	nbr = ft_itoa(nb);
	if (g_f == 1 && ft_strcmp("./minishell", ft_fix_gstr()) != 0)
	{
		g_rep_g_fail = 131;
		g_fail = 131;
		ft_putstr_fd("Quit: ", 2);
		ft_putendl_fd(nbr, 2);
	}
	else if (ft_strcmp("./minishell", ft_fix_gstr()) != 0)
		ft_putstr_fd("\b\b  \b\b", 2);
	ft_memdel(nbr);
}

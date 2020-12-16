/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:00:26 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/10 17:08:44 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(void)
{
	t_upe	*temp;
	int		i;

	temp = g_env_v;
	i = 0;
	g_fail = 0;
	while (i < g_len_env)
	{
		ft_putstr(temp->key);
		ft_putchar('=');
		ft_putstr(temp->value);
		ft_putchar('\n');
		temp = temp->next;
		i++;
	}
	exit(0);
}

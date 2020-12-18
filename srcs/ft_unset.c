/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:12:59 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/18 19:24:25 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	lstadd_declare(t_upe **alst, char *key, char *value)
{
	t_upe *env;

	delkey_declare(alst, key);
	env = lstnew(key, value);
	env->next = *alst;
	*alst = env;
	g_len_declare++;
}

void	delkey_declare(t_upe **alst, char *key)
{
	t_upe	*tmp;
	int		i;

	tmp = *alst;
	i = 0;
	if (*alst == NULL)
		return ;
	while (ft_strcmp(tmp->key, key) && tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	if (ft_strcmp(tmp->key, key))
		return ;
	delpos(alst, i);
	g_len_declare--;
}

void	ft_unset(char **s)
{
	int i;

	i = 1;
	g_fail = 0;
	while (s[i] != NULL)
	{
		delkey(&g_env_v, s[i]);
		delkey_declare(&g_declare, s[i]);
		free(s[i]);
		i++;
	}
	if (g_indice == 1)
		exit(0);
}

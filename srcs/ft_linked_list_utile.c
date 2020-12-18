/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list_utile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:48:50 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/18 18:15:25 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (-128);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}

t_upe	*lstnew(char *key, char *value)
{
	t_upe		*env;

	if (!(env = malloc(sizeof(t_upe))))
		return (NULL);
	if (key)
		env->key = ft_strdup(key);
	if (value)
		env->value = ft_strdup(value);
	env->next = NULL;
	return (env);
}

void	freenode(t_upe **alst)
{
	t_upe *tmp;

	tmp = *alst;
	if (!tmp)
		return ;
	if (tmp->key)
		free(tmp->key);
	if (tmp->value)
		free(tmp->value);
	free(tmp);
}

void	delpos(t_upe **alst, int position)
{
	t_upe	*tmp;
	t_upe	*tmp2;
	t_upe	*next;
	int		i;

	i = 0;
	tmp = NULL;
	tmp2 = NULL;
	next = NULL;
	tmp = *alst;
	if (position == 0)
	{
		*alst = tmp->next;
		freenode(&tmp);
		return ;
	}
	i = -1;
	while (++i < position - 1 && tmp != NULL)
		tmp = tmp->next;
	if (tmp == NULL || tmp->next == NULL)
		return ;
	next = tmp->next->next;
	tmp2 = tmp->next;
	freenode(&tmp2);
	tmp->next = next;
}

void	delkey(t_upe **alst, char *key)
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
	g_len_env--;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 23:34:40 by amoujane          #+#    #+#             */
/*   Updated: 2019/10/21 23:34:51 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *prev;

	if (!alst || !new)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		(*alst)->next = NULL;
	}
	prev = *alst;
	while (prev->next != NULL)
	{
		prev = prev->next;
	}
	prev->next = new;
	new->next = NULL;
}

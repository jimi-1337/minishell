/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 23:35:48 by amoujane          #+#    #+#             */
/*   Updated: 2019/10/21 23:35:51 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *prev;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		prev = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = prev;
	}
	lst = NULL;
}

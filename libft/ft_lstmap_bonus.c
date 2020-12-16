/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 23:38:11 by amoujane          #+#    #+#             */
/*   Updated: 2019/10/24 17:56:07 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nv;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	if (!(nv = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	nv->next = NULL;
	head = nv;
	while (lst)
	{
		nv->content = f(lst->content);
		if (lst->next)
		{
			if (!(nv->next = (t_list*)malloc(sizeof(t_list))))
			{
				ft_lstclear(&head, del);
				return (NULL);
			}
			nv = nv->next;
			nv->next = NULL;
		}
		lst = lst->next;
	}
	return (head);
}

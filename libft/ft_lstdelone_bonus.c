/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 23:35:09 by amoujane          #+#    #+#             */
/*   Updated: 2019/10/21 23:35:11 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *alst, void (*del)(void *))
{
	if (!alst || !del)
		return ;
	if (alst)
	{
		(*del)(alst->content);
		free(alst);
	}
}

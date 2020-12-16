/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 23:21:06 by amoujane          #+#    #+#             */
/*   Updated: 2019/10/16 23:21:09 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			l;

	str = (unsigned char*)s;
	l = 0;
	while (l < n)
	{
		if (str[l] == (unsigned char)c)
			return ((void*)&str[l]);
		l++;
	}
	return (0);
}

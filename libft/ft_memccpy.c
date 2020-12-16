/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 23:19:44 by amoujane          #+#    #+#             */
/*   Updated: 2019/10/16 23:19:47 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	unsigned char *s;
	unsigned char *d;

	s = (unsigned char*)src;
	d = (unsigned char*)dest;
	while (size--)
	{
		*(d) = *(s);
		if (*s == (unsigned char)c)
			return (d + 1);
		s++;
		d++;
	}
	return (NULL);
}

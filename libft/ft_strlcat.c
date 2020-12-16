/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 21:12:45 by amoujane          #+#    #+#             */
/*   Updated: 2019/10/23 22:38:40 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t slen;
	size_t dlen;
	size_t i;
	size_t j;

	slen = ft_strlen(src);
	if (!dst && size == 0)
		return (slen);
	dlen = ft_strlen(dst);
	if (size <= dlen)
		return (size + slen);
	else
	{
		i = dlen;
		j = 0;
		while (src[j] && i < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (slen + dlen);
	}
}

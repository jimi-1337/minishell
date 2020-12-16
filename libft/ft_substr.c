/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 23:51:43 by amoujane          #+#    #+#             */
/*   Updated: 2019/10/18 23:51:47 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	c;
	char	*nstr;

	if (!(s))
		return (NULL);
	nstr = (char *)malloc((len + 1) * sizeof(char));
	if (!(nstr))
		return (NULL);
	c = 0;
	while (*s && c < len && ft_strlen(s) > start)
	{
		nstr[c] = *(char *)(s + start + c);
		c++;
	}
	nstr[c] = '\0';
	return (nstr);
}

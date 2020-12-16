/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 03:25:58 by amoujane          #+#    #+#             */
/*   Updated: 2019/10/21 03:26:00 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!new)
		return (NULL);
	new[len] = '\0';
	while (s[i] != '\0')
	{
		new[i] = (f)(i, s[i]);
		i++;
	}
	return (new);
}

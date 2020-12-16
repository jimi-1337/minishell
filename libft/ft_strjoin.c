/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 23:55:44 by amoujane          #+#    #+#             */
/*   Updated: 2019/10/18 23:55:45 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*text;
	size_t	i;
	size_t	size;

	i = 0;
	if (!s1)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(text = malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		text[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		text[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	text[size] = '\0';
	return (text);
}

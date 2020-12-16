/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewrite_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:42:48 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/11 19:44:58 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_super_join(char *s1, char *s2, char *s3)
{
	char	*ret;
	int		i;
	int		j;

	i = -1;
	j = 0;
	ret = (char*)malloc(sizeof(char) * \
	(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1));
	while (s1[++i] != '\0')
		ret[i] = s1[i];
	while (s2[j] != '\0')
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	j = 0;
	while (s3[j] != '\0')
	{
		ret[i] = s3[j];
		j++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strcut(char *str, int start, int len)
{
	char	*s;
	int		num;
	int		i;

	num = 0;
	i = 0;
	if (len == 0 || start >= (int)ft_strlen(str))
		return (ft_strdup(""));
	if (len < 0)
		len = ft_strlen(str) - start;
	s = (char*)malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		s[i] = str[start];
		start++;
		i++;
	}
	s[i] = '\0';
	return (s);
}

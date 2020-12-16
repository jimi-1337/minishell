/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:59:58 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/10 19:14:30 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_skip_space(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	return (i);
}

int		ft_putstr_c(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int		ft_var_check(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int		ft_strlenn(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

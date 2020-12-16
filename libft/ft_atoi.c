/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 23:28:40 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/16 19:53:27 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int			ft_signe(const char *s)
{
	int sig;

	sig = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sig = -1;
	}
	return (sig);
}

long long			ft_atoi(const char *s)
{
	int					signe;
	long long			result;
	long long			val;

	result = 0;
	val = 0;
	while ((*s == ' ' || *s == '\t' || *s == '\r' || *s == '\v'
				|| *s == '\f' || *s == '\n') && *s)
		s++;
	signe = ft_signe(s);
	if (*s == '-' || *s == '+')
		s++;
	while (*s != '\0' && *s >= '0' && *s <= '9')
	{
		val = result;
		result = (result * 10) + ((*s - '0') * (signe));
		if (signe == 1 && result < val)
			return (-1);
		if (signe == -1 && result > val)
			return (0);
		s++;
	}
	return (result);
}

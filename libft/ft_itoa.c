/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 23:49:59 by amoujane          #+#    #+#             */
/*   Updated: 2019/10/30 21:19:48 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_digitnb(int n)
{
	long		size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size++);
}

static int				ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char					*ft_itoa(int n)
{
	int			nb;
	int			length;
	char		*nstr;

	nb = n;
	length = ft_digitnb(nb);
	if (!(nstr = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	nstr[length] = '\0';
	length--;
	if (nb < 0)
		nb = -nb;
	while (length >= 0)
	{
		nstr[length] = (nb % 10) + '0';
		length--;
		nb /= 10;
	}
	if (ft_sign(n))
		nstr[0] = '-';
	return (nstr);
}

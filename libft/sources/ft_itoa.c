/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeda   <gmeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 21:17:03 by gmeda             #+#    #+#             */
/*   Updated: 2020/04/24 13:23:44 by gmeda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_numlen(int n, int minus)
{
	int numlen;

	numlen = 1;
	while ((n /= 10))
		numlen++;
	return (numlen + minus);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		numlen;
	int		minus;
	int		digit;

	minus = (n < 0) ? 1 : 0;
	numlen = ft_numlen(n, minus);
	if ((str = ft_strnew(numlen)))
	{
		str[numlen--] = '\0';
		while (numlen >= minus)
		{
			digit = n % 10;
			str[numlen--] = FT_ABS(digit) + '0';
			n /= 10;
		}
		if (minus)
			str[0] = '-';
	}
	return (str);
}

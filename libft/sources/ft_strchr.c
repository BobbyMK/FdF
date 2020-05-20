/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeda   <gmeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 18:40:01 by gmeda             #+#    #+#             */
/*   Updated: 2020/04/24 13:22:33 by gmeda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	sym;

	ptr = (char *)s;
	sym = (char)c;
	while (*ptr && !(*ptr == sym))
		ptr++;
	return ((*ptr == sym) ? ptr : NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeda   <gmeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:06:31 by gmeda             #+#    #+#             */
/*   Updated: 2020/04/24 13:23:25 by gmeda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *res;

	if ((res = (t_list *)ft_memalloc(sizeof(t_list))))
	{
		if (!content)
		{
			res->content = NULL;
			res->content_size = 0;
		}
		else
		{
			if (!(res->content = ft_memalloc(content_size)))
			{
				free(res);
				return (NULL);
			}
			ft_memcpy(res->content, content, content_size);
			res->content_size = content_size;
		}
		res->next = NULL;
	}
	return (res);
}

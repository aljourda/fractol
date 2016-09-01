/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 09:49:37 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/30 16:52:11 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(t_list));
	if (list != 0)
	{
		if (content == 0)
		{
			list->content = 0;
			list->content_size = 0;
			list->next = 0;
		}
		else
		{
			if ((list->content = ft_memalloc(content_size)) != 0)
			{
				ft_memcpy(list->content, content, content_size);
				list->content_size = content_size;
				list->next = 0;
			}
			else
				ft_memdel((void**)&list);
		}
	}
	return (list);
}

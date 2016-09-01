/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 09:50:36 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/30 16:52:54 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*fresult;
	t_list	*tmp;

	fresult = f(lst);
	result = ft_lstnew(fresult->content, fresult->content_size);
	if (result != 0)
	{
		tmp = result;
		lst = lst->next;
		while (lst)
		{
			fresult = f(lst);
			tmp->next = ft_lstnew(fresult->content, fresult->content_size);
			if (tmp->next == 0)
				return (0);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (result);
}

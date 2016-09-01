/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 09:50:00 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/30 16:53:21 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*lst;

	if (alst)
	{
		lst = (*alst);
		while (lst)
		{
			next = lst->next;
			ft_lstdelone(&lst, (*del));
			free(lst);
			lst = next;
		}
		*alst = 0;
	}
}

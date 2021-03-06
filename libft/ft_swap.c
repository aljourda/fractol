/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:44:16 by aljourda          #+#    #+#             */
/*   Updated: 2016/01/14 13:57:25 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(char *p1, char *p2)
{
	char	tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void	ft_swap_int(int *p1, int *p2)
{
	int	tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:22:27 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/29 13:46:52 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	value;

	str = (char*)s;
	value = (char)c;
	while (n > 0)
	{
		if (*str == value)
			return ((void*)str);
		n--;
		str++;
	}
	return (0);
}

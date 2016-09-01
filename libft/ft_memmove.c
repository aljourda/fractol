/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:21:51 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/29 13:43:06 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (destination <= source || source >= (destination + len))
	{
		while (len--)
			*destination++ = *source++;
	}
	else
	{
		destination = destination + len - 1;
		source = source + len - 1;
		while (len--)
			*destination-- = *source--;
	}
	return (dst);
}

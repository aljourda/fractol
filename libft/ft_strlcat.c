/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:31:29 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/29 14:05:23 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*source;
	size_t	size_dst;
	size_t	size_src;
	int		len;

	size_dst = ft_strlen((const char*)dst);
	size_src = ft_strlen(src);
	source = (char*)src;
	len = (int)(size - 1 - size_dst);
	if (size <= size_dst)
		return (size + size_src);
	while (*dst)
		dst++;
	while (*source && len > 0)
	{
		*dst++ = *source++;
		len--;
	}
	*dst = 0;
	return (size_dst + size_src);
}

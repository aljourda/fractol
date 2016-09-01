/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:30:24 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/29 13:59:21 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = s1;
	while (*dst != 0)
		dst++;
	while (*s2 != 0 && i++ < n)
		*dst++ = *s2++;
	*dst = 0;
	return (s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:35:42 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/29 14:23:20 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	length;
	size_t	i;
	char	*ptr;

	if (n == 0)
		return (0);
	if (*s2 == 0)
		return ((char*)s1);
	ptr = (char*)s1;
	length = ft_strlen(s2);
	i = 0;
	while (*ptr && i <= (n - length))
	{
		if (ft_strncmp(ptr, s2, length) == 0)
			return ((char *)ptr);
		ptr++;
		i++;
	}
	return (0);
}

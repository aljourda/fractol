/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:33:46 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/29 14:12:30 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	length;
	char	*ptr;

	if (*s2 == 0)
		return ((char*)s1);
	ptr = (char*)s1;
	length = ft_strlen(s2);
	while (*ptr)
	{
		if (ft_strncmp(ptr, s2, length) == 0)
			return ((char *)ptr);
		ptr++;
	}
	return (0);
}

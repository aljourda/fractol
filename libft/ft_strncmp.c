/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:37:03 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/29 14:29:10 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (n-- > 0)
	{
		if (*str1 != *str2)
		{
			if (*str1 > *str2)
				return (1);
			else
				return (-1);
		}
		if (*str1 == 0)
			return (0);
		str1++;
		str2++;
	}
	return (0);
}

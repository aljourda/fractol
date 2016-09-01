/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 09:45:54 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/29 11:22:23 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	char	*str;
	int		i;

	ptr = ft_strnew(ft_strlen(s));
	str = (char*)s;
	if (ptr != 0)
	{
		i = 0;
		while (*str != 0)
			ptr[i++] = f(*str++);
	}
	return (ptr);
}

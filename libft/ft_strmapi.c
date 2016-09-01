/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 09:46:08 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/29 11:25:16 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;
	char			*str;

	str = (char*)s;
	ptr = ft_strnew(ft_strlen(s));
	if (ptr != 0)
	{
		i = 0;
		while (*str != 0)
		{
			ptr[i] = f(i, *str++);
			i++;
		}
	}
	return (ptr);
}

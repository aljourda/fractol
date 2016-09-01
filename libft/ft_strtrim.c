/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 09:47:13 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/29 12:19:13 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strtrim_len(char *src)
{
	size_t		i;
	char		*end;

	while (*src != 0 && (*src == ' ' || *src == '\t' || *src == '\n'))
		src++;
	i = ft_strlen(src);
	end = src + i - 1;
	while (end > src && (*end == ' ' || *end == '\t'
		|| *end == '\n' || *end == 0))
	{
		i--;
		end--;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char			*str;
	char			*src;

	src = (char*)s;
	while (*src != 0 && (*src == ' ' || *src == '\t' || *src == '\n'))
		src++;
	str = ft_strnew(ft_strtrim_len(src));
	if (str != 0)
	{
		ft_strncpy(str, src, ft_strtrim_len(src));
	}
	return (str);
}

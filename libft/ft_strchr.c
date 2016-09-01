/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:32:11 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/26 15:21:06 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	value;

	str = (char*)s;
	value = (char)c;
	while (*str != value && *str != 0)
		str++;
	if (*str == value)
		return (str);
	return (0);
}

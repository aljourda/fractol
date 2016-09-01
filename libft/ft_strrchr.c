/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:32:56 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/29 14:10:26 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	value;

	str = ft_strchr(s, 0);
	value = (char)c;
	while (*str != value && str > s)
		str--;
	if (*str == value)
		return (str);
	return (0);
}

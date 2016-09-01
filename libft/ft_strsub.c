/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 09:46:45 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/29 12:00:59 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;

	str = 0;
	if (start > ft_strlen(s) && *str == 0)
		return (0);
	i = 0;
	str = ft_strnew(len);
	while (*(s + start) != 0 && i < len && str != 0)
		str[i++] = s[start++];
	return (str);
}

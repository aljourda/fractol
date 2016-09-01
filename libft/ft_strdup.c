/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:25:16 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/29 13:54:15 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*dst;

	dst = ft_strnew(ft_strlen(s1));
	if (dst != 0)
		ft_strcpy(dst, s1);
	return (dst);
}

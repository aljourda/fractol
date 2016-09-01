/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 09:46:58 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/29 12:07:15 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;

	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str != 0)
	{
		ft_strcpy(str, s1);
		ft_strcpy(str + ft_strlen(s1), s2);
	}
	return (str);
}

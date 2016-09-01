/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:37:46 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/29 14:40:28 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	value;
	char	*s;
	int		sign;

	s = (char*)str;
	value = 0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	if ((*s == '-' || *s == '+') && ft_isdigit(*(s + 1)))
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		value *= 10;
		value += *s - '0';
		s++;
	}
	return (int)(value * sign);
}

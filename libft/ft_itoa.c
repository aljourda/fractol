/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 09:47:38 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/29 12:52:42 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_int(int n)
{
	long		uval;
	size_t		i;

	i = 0;
	uval = (long)n;
	if (uval < 0)
	{
		uval *= -1;
		i++;
	}
	if (uval == 0)
		i++;
	else
		while (uval > 0)
		{
			uval /= 10;
			i++;
		}
	return (i + 1);
}

char			*ft_itoa(int n)
{
	long	uval;
	char	*result;
	int		i;

	i = 0;
	uval = (long)n;
	if (n < 0)
		uval *= -1;
	result = (char*)malloc(ft_count_int(n));
	if (result)
	{
		while (uval > 0)
		{
			*(result + i) = uval % 10 + '0';
			i++;
			uval /= 10;
		}
		if (n == 0)
			*(result + i++) = '0';
		else if (n < 0)
			*(result + i++) = '-';
		*(result + i) = 0;
		ft_strrev(result);
	}
	return (result);
}

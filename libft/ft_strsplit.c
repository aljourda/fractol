/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 09:47:27 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/29 13:20:17 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_tonext(char *str, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*str != 0 && *str != c)
	{
		str++;
		cnt++;
	}
	return (cnt);
}

static size_t	ft_split_count(char *s, char c)
{
	size_t	i;
	int		is_word;

	i = 0;
	is_word = 0;
	while (*s)
	{
		if (is_word == 0 && *s != c)
		{
			is_word = 1;
			i++;
		}
		else if (is_word == 1 && *s == c)
			is_word = 0;
		s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**strings;
	size_t		strings_size;
	char		*str;
	size_t		i;

	strings_size = ft_split_count((char*)s, c);
	strings = (char**)malloc(sizeof(char*) * (strings_size + 1));
	if (strings != 0)
	{
		i = 0;
		str = (char*)s;
		while (i < strings_size)
		{
			if (ft_count_tonext(str, c) > 0)
			{
				if ((strings[i] = ft_strnew(ft_count_tonext(str, c))) != 0)
					ft_strncpy(strings[i], str, ft_count_tonext(str, c));
				str += ft_count_tonext(str, c);
				i++;
			}
			str++;
		}
		strings[i] = 0;
	}
	return (strings);
}

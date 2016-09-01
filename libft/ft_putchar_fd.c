/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 09:48:42 by aljourda          #+#    #+#             */
/*   Updated: 2015/11/29 10:30:34 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar_fd_unsigned(unsigned short c, int fd)
{
	write(fd, (void*)&c, 1);
}

void		ft_putchar_fd(char c, int fd)
{
	unsigned short ch;

	ch = 0xff;
	ch &= (unsigned short)(c);
	if (ch < 0x80)
	{
		ft_putchar_fd_unsigned(ch, fd);
	}
	else
	{
		ft_putchar_fd_unsigned(0xC0 | (ch >> 6), fd);
		ft_putchar_fd_unsigned(0x80 | (ch & 0x3F), fd);
	}
}

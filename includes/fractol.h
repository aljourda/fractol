/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 16:41:33 by aljourda          #+#    #+#             */
/*   Updated: 2016/08/23 16:41:40 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <libft.h>
# include "fractal.h"

typedef struct	s_env
{
	int			width;
	int			height;
	void		*mlx_ptr;
	void		*win_ptr;
	int			bpp;
	int			sl;
	int			edn;
	int			*img;
	char		*tmp;
	t_fractal	*fractal;
}				t_env;

t_env			*ft_use_env(int action);
int				expose_hook(void *param);
int				mouse_hook_motion(int x, int y, void *param);
int				mouse_hook_wheel(int pos, void *param);
int				key_hook(int keycode, void *param);

#endif

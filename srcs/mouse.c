/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 17:42:27 by aljourda          #+#    #+#             */
/*   Updated: 2016/08/25 17:42:39 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void		key_change_exit(t_env *env, int keycode)
{
	int			fractal;

	if (keycode == 53)
	{
		ft_use_env(0);
		exit(1);
	}
	if (env != 0 && env->fractal != 0 && keycode == 6)
	{
		fractal = env->fractal->type;
		ft_memdel((void**)&(env->fractal));
		env->fractal = fractal_init(fractal, env->width, env->height);
	}
	if (env != 0 && env->fractal != 0 && keycode == 7)
	{
		fractal = env->fractal->type;
		ft_memdel((void**)&(env->fractal));
		env->fractal = fractal_init(((fractal + 1) % 3) + 1,
			env->width, env->height);
	}
}

int				key_hook(int keycode, void *param)
{
	t_env		*env;

	env = ft_use_env(-1);
	param = 0;
	key_change_exit(env, keycode);
	if (env != 0 && env->fractal != 0 && keycode == 126)
		env->fractal->y += 0.1;
	if (env != 0 && env->fractal != 0 && keycode == 125)
		env->fractal->y -= 0.1;
	if (env != 0 && env->fractal != 0 && keycode == 123)
		env->fractal->x += 0.1;
	if (env != 0 && env->fractal != 0 && keycode == 124)
		env->fractal->x -= 0.1;
	if (env != 0 && env->fractal != 0 && keycode == 69)
		fractal_zoom(env->fractal, 0.22);
	if (env != 0 && env->fractal != 0 && keycode == 78)
		fractal_zoom(env->fractal, -0.22);
	expose_hook(0);
	return (0);
}

int				mouse_hook_motion(int x, int y, void *param)
{
	t_env		*env;

	env = ft_use_env(-1);
	param = 0;
	if (env != 0 && env->fractal != 0 && env->fractal->type == 1)
	{
		if (x > 0 && x < env->fractal->w && y > 0 && y < env->fractal->h)
		{
			env->fractal->cre = (double)x / (double)env->fractal->w * 4 - 2;
			env->fractal->cim = (double)y / (double)env->fractal->h * 4 - 2;
			expose_hook(0);
		}
	}
	return (0);
}

int				mouse_hook_wheel(int pos, void *param)
{
	t_env		*env;

	env = ft_use_env(-1);
	param = 0;
	if ((pos == 4 || pos == 5) && env != 0 && env->fractal != 0)
	{
		if (pos == 4)
			fractal_zoom(env->fractal, -0.2);
		if (pos == 5)
			fractal_zoom(env->fractal, 0.2);
		expose_hook(0);
	}
	return (0);
}

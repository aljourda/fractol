/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 14:42:15 by aljourda          #+#    #+#             */
/*   Updated: 2016/08/16 14:42:17 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_env			*ft_use_env(int action)
{
	static t_env		*env;

	if (action == 1 || action == 2 || action == 3)
	{
		env = (t_env*)ft_memalloc(sizeof(t_env));
		if (env != 0)
		{
			env->width = 600;
			env->height = 490;
			env->fractal = fractal_init(action, env->width, env->height);
			env->mlx_ptr = mlx_init();
			env->win_ptr = mlx_new_window(env->mlx_ptr, env->width,
				env->height, "fractol");
			env->img = mlx_new_image(env->mlx_ptr, env->width, env->height);
		}
		else
			action = 0;
	}
	if (action == 0 && env != 0)
	{
		ft_memdel((void**)&(env->fractal));
		ft_memdel((void**)&(env));
	}
	return (env);
}

static void		img_put_px(t_env *env, unsigned long color, int x, int y)
{
	env->tmp[y * env->sl + x * env->bpp / 8] = (color & 0xFF);
	env->tmp[y * env->sl + x * env->bpp / 8 + 1] = (color & 0xFF00) >> 8;
	env->tmp[y * env->sl + x * env->bpp / 8 + 2] = (color & 0xFF0000) >> 16;
}

int				expose_hook(void *param)
{
	t_env		*env;
	int			x;
	int			y;

	env = ft_use_env(-1);
	param = 0;
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	if (env->fractal)
	{
		env->tmp = mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->edn);
		y = 0;
		while (y < env->fractal->h)
		{
			x = 0;
			while (x < env->fractal->w)
			{
				img_put_px(env, fractal_get_pixel(env->fractal, x, y), x, y);
				x++;
			}
			y++;
		}
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img, 0, 0);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_env		*env;

	env = 0;
	if (argc == 2)
	{
		if (ft_strcmp("mandelbrot", argv[1]) == 0)
			env = ft_use_env(2);
		else if (ft_strcmp("tricorn", argv[1]) == 0)
			env = ft_use_env(3);
		else if (ft_strcmp("julia", argv[1]) == 0)
			env = ft_use_env(1);
		if (env != 0 && env->mlx_ptr != 0)
		{
			mlx_hook(env->win_ptr, 4, 0, mouse_hook_wheel, 0);
			mlx_hook(env->win_ptr, 6, 0, mouse_hook_motion, 0);
			mlx_hook(env->win_ptr, 2, 3, key_hook, 0);
			mlx_expose_hook(env->win_ptr, expose_hook, 0);
			mlx_loop(env->mlx_ptr);
		}
	}
	ft_putstr("Usage : fractol {julia,mandelbrot,tricorn}\n");
	ft_use_env(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 14:04:19 by aljourda          #+#    #+#             */
/*   Updated: 2016/08/25 16:49:38 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <math.h>
#include <stdlib.h>

t_fractal		*fractal_init(int type, int width, int height)
{
	t_fractal	*f;

	if ((f = (t_fractal*)malloc(sizeof(t_fractal))) != 0)
	{
		f->x = 0;
		f->y = 0;
		f->w = width;
		f->h = height;
		f->n = 512;
		f->z = 1;
		f->cre = 0;
		f->cim = 0;
		if (type == 1)
		{
			f->cre = -0.7;
			f->cim = 0.27015;
		}
		f->type = type;
	}
	return (f);
}

void			fractal_zoom(t_fractal *f, double value)
{
	f->z += value;
	if (f->z <= 0.0)
		f->z -= value;
}

static int		fractal_get_mt(t_fractal *f, int x, int y, int param)
{
	double	value[2];
	double	old[2];
	double	pr;
	double	pi;
	int		i;

	pr = 1.5 * (x - f->w / 2) / (0.5 * f->z * f->w) + f->x;
	pi = (y - f->h / 2) / (0.5 * f->z * f->h) + f->y;
	value[0] = 0;
	value[1] = 0;
	i = 0;
	while (i < f->n)
	{
		old[0] = value[0];
		old[1] = value[1];
		value[0] = old[0] * old[0] - old[1] * old[1] + pr;
		value[1] = param * old[0] * old[1] + pi;
		if ((value[0] * value[0] + value[1] * value[1]) > 4)
			break ;
		i++;
	}
	return (hsv_to_rgb((i % 256) / 255.0f, 1.0f, (i < f->n) ? 1.0 : 0.0));
}

int				fractal_get_pixel(t_fractal *f, int x, int y)
{
	double	value[2];
	double	old[2];
	int		i;

	if (f->type == 1)
	{
		value[0] = 1.5 * (x - f->w / 2) / (0.5 * f->z * f->w) + f->x;
		value[1] = (y - f->h / 2) / (0.5 * f->z * f->h) + f->y;
		i = -1;
		while (++i < f->n)
		{
			old[0] = value[0];
			old[1] = value[1];
			value[0] = old[0] * old[0] - old[1] * old[1] + f->cre;
			value[1] = 2 * old[0] * old[1] + f->cim;
			if ((value[0] * value[0] + value[1] * value[1]) > 4)
				break ;
		}
		return (hsv_to_rgb((i % 256) / 255.0f, 1.0f, (i < f->n) ? 1.0 : 0.0));
	}
	else if (f->type == 2)
		return (fractal_get_mt(f, x, y, 2));
	else
		return (fractal_get_mt(f, x, y, -2));
}

int				hsv_to_rgb(float hue, float saturation, float value)
{
	int		color;
	float	tmp[5];

	color = GETRGB(HSV(value), HSV(value), HSV(value));
	if (saturation != 0.0)
	{
		tmp[0] = (hue - (float)floor(hue)) * 6;
		tmp[1] = tmp[0] - (float)floor(tmp[0]);
		tmp[2] = value * (1.0 - saturation);
		tmp[3] = value * (1.0 - saturation * tmp[1]);
		tmp[4] = value * (1.0 - saturation * (1.0 - tmp[1]));
		if ((int)tmp[0] == 0)
			color = GETRGB(HSV(value), HSV(tmp[4]), HSV(tmp[2]));
		else if ((int)tmp[0] == 1)
			color = GETRGB(HSV(tmp[3]), HSV(value), HSV(tmp[2]));
		else if ((int)tmp[0] == 2)
			color = GETRGB(HSV(tmp[2]), HSV(value), HSV(tmp[4]));
		else if ((int)tmp[0] == 3)
			color = GETRGB(HSV(tmp[2]), HSV(tmp[3]), HSV(value));
		else if ((int)tmp[0] == 4)
			color = GETRGB(HSV(tmp[4]), HSV(tmp[2]), HSV(value));
		else if ((int)tmp[0] == 5)
			color = GETRGB(HSV(value), HSV(tmp[2]), HSV(tmp[3]));
	}
	return (color);
}

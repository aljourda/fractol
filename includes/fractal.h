/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 13:52:55 by aljourda          #+#    #+#             */
/*   Updated: 2016/08/25 13:53:42 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# define GETRGB(r,g,b) (((r) << 16) | ((g) << 8)| ((b) << 0))
# define HSV(value) (int)((value) * 255.0f + 0.5)

typedef struct	s_fractal
{
	double		x;
	double		y;
	double		z;
	double		w;
	double		h;
	int			n;
	double		cre;
	double		cim;
	int			type;
}				t_fractal;

t_fractal		*fractal_init(int type, int width, int height);
void			fractal_zoom(t_fractal *f, double value);
int				fractal_get_pixel(t_fractal *f, int x, int y);
int				hsv_to_rgb(float hue, float saturation, float value);

#endif

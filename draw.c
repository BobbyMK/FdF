/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeda <gmeda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:20:39 by gmeda             #+#    #+#             */
/*   Updated: 2020/01/23 16:07:38 by gmeda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void		isometric(float *x, float *y, int z, t_fdf *map)
{
	int new_x;
	int new_y;

	new_x = *x;
	new_y = *y;
	*x = (new_x - new_y) * cos(map->angle);
	*y = (new_x + new_y) * sin(map->angle) - z;
}

void		zoom_n_shift(float *d, t_fdf *map)
{
	int		z;
	int		z1;

	z = map->height_matrix[(int)d[2]][(int)d[1]] * map->z_scale;
	z1 = map->height_matrix[(int)d[4]][(int)d[3]] * map->z_scale;
	d[1] *= map->zoom;
	d[2] *= map->zoom;
	d[3] *= map->zoom;
	d[4] *= map->zoom;
	isometric(&d[1], &d[2], z, map);
	isometric(&d[3], &d[4], z1, map);
	d[1] += map->shift_x;
	d[2] += map->shift_y;
	d[3] += map->shift_x;
	d[4] += map->shift_y;
	map->color = (z || z1) ? 0xff0000 : 0xe0ffff;
}

void		bresenham(float *s, t_fdf *map)
{
	float	*d;
	float	x_step;
	float	y_step;
	int		max;

	max = 5;
	d = (float*)malloc(sizeof(float) * 5);
	while (max--)
		d[max] = s[max];
	zoom_n_shift(d, map);
	x_step = d[3] - d[1];
	y_step = d[4] - d[2];
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(d[1] - d[3]) || (int)(d[2] - d[4]))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, d[1], d[2], map->color);
		d[1] += x_step;
		d[2] += y_step;
	}
	free(d);
}

void		cycles(t_fdf *map, float *d)
{
	while (d[2] < map->y)
	{
		d[1] = 0;
		while (d[1] < map->x)
		{
			if (d[1] < map->x - 1)
			{
				d[3] = d[1] + 1;
				bresenham(d, map);
				d[3] = d[1];
			}
			if (d[2] < map->y - 1)
			{
				d[4] = d[2] + 1;
				bresenham(d, map);
				d[4] = d[2];
			}
			d[1]++;
			d[3] = d[1];
		}
		d[2]++;
		d[4] = d[2];
	}
}

void		draw(t_fdf *map)
{
	float	*d;

	d = (float*)malloc(sizeof(float) * 5);
	d[4] = 0;
	d[2] = 0;
	cycles(map, d);
	free(d);
}

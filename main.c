/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeda <gmeda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:20:44 by gmeda             #+#    #+#             */
/*   Updated: 2020/01/14 17:27:01 by gmeda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		input_key(int key, t_fdf *map)
{
	(key == 126) ? map->shift_y += map->zoom / 2 : 0;
	(key == 125) ? map->shift_y -= map->zoom / 2 : 0;
	(key == 123) ? map->shift_x += map->zoom / 2 : 0;
	(key == 124) ? map->shift_x -= map->zoom / 2 : 0;
	(key == 69) ? map->zoom += 10 : 0;
	(key == 78 && map->zoom > 10) ? map->zoom -= 10 : 0;
	(key == 86) ? map->angle -= 0.05 : 0;
	(key == 88) ? map->angle += 0.05 : 0;
	(key == 91) ? map->z_scale += 1 : 0;
	(key == 53) ? exit(0) : 0;
	(key == 84 && map->z_scale > 1) ? map->z_scale -= 1 : 0;
	if (key == 49)
	{
		map->angle = 0.5326;
		map->z_scale = 1;
		map->shift_x = 700;
		map->shift_y = 400;
	}
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	return (0);
}

int		main(int ac, char **av)
{
	t_fdf	*map;

	if (ac == 2)
	{
		map = (t_fdf*)malloc(sizeof(t_fdf));
		read_file(av[1], map);
		map->mlx_ptr = mlx_init();
		map->angle = 0.53;
		map->z_scale = 1;
		map->w_x = 2000;
		map->w_y = 1300;
		map->win_ptr = mlx_new_window(map->mlx_ptr, map->w_x, map->w_y, "FDF");
		map->zoom = 50;
		map->shift_x = 700;
		map->shift_y = 400;
		draw(map);
		mlx_hook(map->win_ptr, 2, 0, input_key, map);
		mlx_loop(map->mlx_ptr);
	}
	else
		ft_putendl_fd("Usage: ./fdf [File]", 2);
	return (0);
}

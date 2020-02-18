/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeda <gmeda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:20:44 by gmeda             #+#    #+#             */
/*   Updated: 2020/02/18 21:13:24 by gmeda            ###   ########.fr       */
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
	(key == 69) ? map->zoom += 5 : 0;
	(key == 78 && map->zoom > 5) ? map->zoom -= 5 : 0;
	(key == 86) ? map->angle -= 0.05 : 0;
	(key == 88) ? map->angle += 0.05 : 0;
	(key == 91) ? map->z_scale += 1 : 0;
	(key == 53) ? exit(0) : 0;
	(key == 84 && map->z_scale > 1) ? map->z_scale -= 1 : 0;
	if (key == 49)
	{
		map->angle = 0.5326;
		map->z_scale = 4;
		map->shift_x = 700;
		map->shift_y = 400;
		map->zoom = 20;
	}
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	return (0);
}

void	ft_error(char *str)
{
	if (ft_strcmp(str, "map") == 0)
		ft_putendl("Map error");
	else if (ft_strcmp(str, "args") == 0)
		ft_putendl("Wrong arguments");
	else if (ft_strcmp(str, "file") == 0)
		ft_putendl("File error");
	else
		ft_putendl("error");
	exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	t_fdf	*map;

	if (ac == 2)
	{
		(!(av[1])) ? ft_error("args") : 0;
		map = (t_fdf*)malloc(sizeof(t_fdf));
		read_file(av[1], map);
		map->mlx_ptr = mlx_init();
		map->angle = 0.53;
		map->z_scale = 4;
		map->w_x = 2000;
		map->w_y = 1300;
		map->win_ptr = mlx_new_window(map->mlx_ptr, map->w_x, map->w_y, "FDF");
		map->zoom = 25;
		map->shift_x = 700;
		map->shift_y = 400;
		draw(map);
		mlx_hook(map->win_ptr, 2, 0, input_key, map);
		mlx_loop(map->mlx_ptr);
	}
	else
		ft_error("args");
	return (0);
}

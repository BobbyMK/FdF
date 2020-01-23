/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeda <gmeda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:20:36 by gmeda             #+#    #+#             */
/*   Updated: 2020/01/23 16:09:10 by gmeda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct		s_fdf
{
	int				x;
	int				y;
	int				**height_matrix;
	int				zoom;
	int				color;
	int				shift_x;
	int				shift_y;
	int				w_x;
	int				w_y;
	int				z_scale;
	void			*mlx_ptr;
	void			*win_ptr;
	double			angle;
}					t_fdf;

void				read_file(char *file_name, t_fdf *data);
void				draw(t_fdf *map);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeda <gmeda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:20:36 by gmeda             #+#    #+#             */
/*   Updated: 2020/02/18 21:00:30 by gmeda            ###   ########.fr       */
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

int					digit_counter(char *line, char c);
int					is_valid(char *line, int x);
int					digit_counter(char *line, char c);
int					get_width(char *file_name);
int					get_length(char *file_name);
int					input_key(int key, t_fdf *map);
void				read_file(char *file_name, t_fdf *data);
void				draw(t_fdf *map);
void				ft_error(char *str);
void				matrix(int *z, char *line);
void				ft_error(char *str);
void				isometric(float *x, float *y, int z, t_fdf *map);
void				zoom_n_shift(float *d, t_fdf *map);
void				bresenham(float *s, t_fdf *map);
void				cycles(t_fdf *map, float *d);

#endif

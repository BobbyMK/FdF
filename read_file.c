/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeda <gmeda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:20:42 by gmeda             #+#    #+#             */
/*   Updated: 2020/02/15 21:32:35 by gmeda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				digit_counter(char *line, char c)
{
	int			count;

	count = 0;
	while (*line)
	{
		while (*line == c)
			line++;
		if (*line)
		{
			count++;
			while (*line && *line != c)
				((*line < '0' || *line > '9') && *line != '\n' && *line != ' ' && *line != '-') ? ft_error("map") : line++;
		}
	}
	return (count);
}

int				get_width(char *file_name)
{
	int			fd;
	char		*line;
	int			width;

	width = 0;
	fd = open(file_name, O_RDONLY, 0);
	(fd != 3) ? ft_error("file") : 0;
	while (get_next_line(fd, &line))
	{
		width++;
		free(line);
	}
	close(fd);
	return (width);
}

int				get_length(char *file_name)
{
	int			fd;
	char		*line;
	int			length;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	length = digit_counter(line, ' ');
	free(line);
	close(fd);
	return (length);
}

void			matrix(int *z, char *line)
{
	char		**nums;
	int			i;

	i = 0;
	nums = ft_strsplit(line, ' ');
	while (nums[i])
	{
		z[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void			read_file(char *file_name, t_fdf *data)
{
	int			i;
	int			fd;
	char		*line;

	data->y = get_width(file_name);
	data->x = get_length(file_name);
	data->height_matrix = (int**)malloc(sizeof(int*) * (data->y + 1));
	i = 0;
	while (i <= data->y)
		data->height_matrix[i++] = (int*)malloc(sizeof(int) * (data->x + 1));
	i = 0;
	fd = open(file_name, O_RDONLY, 0);
	while (get_next_line(fd, &line) && i != data->y/* && is_valid(line, data->x*/)
	{
		matrix(data->height_matrix[i], line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
}

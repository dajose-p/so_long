/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:45:57 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/19 15:06:50 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_line(t_map *map, char *line, void *mlx, void *win, int line_count)
{
	int	img_width;
	int	img_height;
	int i;

	i = 0;
	map->wall_img = mlx_xpm_file_to_image(mlx, map->wall_path, &img_width, &img_height);
	map->floor_img = mlx_xpm_file_to_image(mlx, map->floor_path, &img_width, &img_height);
	map->item_img = mlx_xpm_file_to_image(mlx, map->item_path, &img_width, &img_height);
	map->exit_img = mlx_xpm_file_to_image(mlx, map->exit_path, &img_width, &img_height);
	map->player_img = mlx_xpm_file_to_image(mlx, map->player_path, &img_width, &img_height);
	while (line[i] != '\n')
	{
		if (line[i] == '1')
			mlx_put_image_to_window(mlx, win, map->wall_img, 32*i, line_count*32);
		if (line[i] == 'C')
			mlx_put_image_to_window(mlx, win, map->item_img, 32*i, line_count*32);
		if (line[i] == '0')
			mlx_put_image_to_window(mlx, win, map->floor_img, 32*i, line_count*32);
		if (line[i] == 'E')
			mlx_put_image_to_window(mlx, win, map->exit_img, 32*i, line_count*32);
		if (line[i] == 'P')
			mlx_put_image_to_window(mlx, win, map->player_img, 32*i, line_count*32);
		i++;
	}
}

void	read_map(void *mlx, t_map *map, int fd, char *path, void *mlx_win)
{
	char	*line;
	int	line_count;
	int	max;

	line_count = count_lines(fd, map);
	max = line_count;
	close(fd);
	fd = open(path, O_RDONLY);
	check_map(map, fd, path);
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		draw_line(map, line, mlx, mlx_win, max - line_count);
		free(line);
		line = get_next_line(fd);
		if (*line == '\0')
		{
			free(line);
			line = NULL;
		}
		line_count--;
	}
}

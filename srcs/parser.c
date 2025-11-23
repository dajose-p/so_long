/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:45:57 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/23 18:12:49 by danjose-         ###   ########.fr       */
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
			mlx_put_image_to_window(mlx, win, map->wall_img, 64*i, line_count*64);
		if (line[i] == 'C')
			mlx_put_image_to_window(mlx, win, map->item_img, 64*i, line_count*64);
		if (line[i] == '0')
			mlx_put_image_to_window(mlx, win, map->floor_img, 64*i, line_count*64);
		if (line[i] == 'E')
			mlx_put_image_to_window(mlx, win, map->floor_img, 64*i, line_count*64);
		if (line[i] == 'P')
			mlx_put_image_to_window(mlx, win, map->player_img, 64*i, line_count*64);
		i++;
	}
}

void	duplic_map(t_map *map, char **dup_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			dup_map[i][j] = map->full_map[i][j];
			j++;
		}
		i++;
	}
}

void	read_map(void *mlx, t_map *map, void *mlx_win)
{
	int	i;
	char	**dup_map;
	i = 0;

	dup_map = malloc(map->height + 1 * sizeof(char *));
	while (i < map->height)
	{
		dup_map[i] = malloc(map->width + 1 * sizeof(char));
		i++;
	}
	duplic_map(map, dup_map);
	check_map(map, dup_map);
	i = 0;
	while (i < map->height)
	{
		draw_line(map, map->full_map[i], mlx, mlx_win, i);
		i++;
	}
}

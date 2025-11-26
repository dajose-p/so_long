/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:45:57 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/26 17:53:11 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	load_images(t_map *map)
{
	int	img_width;
	int	img_height;

	map->wall_img = mlx_xpm_file_to_image(map->mlx, map->wall_path, &img_width,
			&img_height);
	map->floor_img = mlx_xpm_file_to_image(map->mlx, map->floor_path,
			&img_width, &img_height);
	map->item_img = mlx_xpm_file_to_image(map->mlx, map->item_path, &img_width,
			&img_height);
	map->exit_img = mlx_xpm_file_to_image(map->mlx, map->exit_path, &img_width,
			&img_height);
	map->player_img = mlx_xpm_file_to_image(map->mlx, map->player_path,
			&img_width, &img_height);
}

void	draw_line(t_map *map, char *line, int line_count)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '1')
			mlx_put_image_to_window(map->mlx, map->mlx_win, map->wall_img, 64
				* i, line_count * 64);
		if (line[i] == 'C')
			mlx_put_image_to_window(map->mlx, map->mlx_win, map->item_img, 64
				* i, line_count * 64);
		if (line[i] == '0')
			mlx_put_image_to_window(map->mlx, map->mlx_win, map->floor_img, 64
				* i, line_count * 64);
		if (line[i] == 'E')
			mlx_put_image_to_window(map->mlx, map->mlx_win, map->floor_img, 64
				* i, line_count * 64);
		if (line[i] == 'P')
			mlx_put_image_to_window(map->mlx, map->mlx_win, map->player_img, 64
				* i, line_count * 64);
		i++;
	}
}

void	duplic_map(t_map *map, char **dup_map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		dup_map[i] = ft_strdup(map->full_map[i]);
		i++;
	}
	dup_map[i] = NULL;
}

void	draw_map(t_map *map)
{
	int	i;

	i = 0;
	load_images(map);
	while (i < map->height)
	{
		draw_line(map, map->full_map[i], i);
		i++;
	}
}

void	read_map(t_map *map)
{
	int		i;
	char	**dup_map;

	i = 0;
	dup_map = malloc((map->height + 1) * sizeof(char *));
	duplic_map(map, dup_map);
	check_map(map, dup_map);
	i = 0;
	while (dup_map[i])
	{
		free(dup_map[i]);
		i++;
	}
	free(dup_map);
}

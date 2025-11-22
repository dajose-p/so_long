/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:41:55 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/22 19:58:30 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_items(t_map *map, int width, int height)
{
	int	i;

	i = 0;
	map->wall_path = "/home/danjose-/Cursus/so_long/textures/wall.xpm";
	map->floor_path = "/home/danjose-/Cursus/so_long/textures/floor.xpm";
	map->exit_path = "/home/danjose-/Cursus/so_long/textures/exit.xpm";
	map->player_path = "/home/danjose-/Cursus/so_long/textures/player.xpm";
	map->item_path = "/home/danjose-/Cursus/so_long/textures/item.xpm";
	map->full_map = malloc(height + 1 * sizeof(char *));
	while (i < height)
	{
		map->full_map[i] = malloc(width + 1 * sizeof(char));
		i++;
	}
}

int main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	int	fd;
	t_map *map;

	(void)argc;
	(void)mlx_win;
	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	fd = open(argv[1], O_RDONLY);
	check_size(map, fd);
	close(fd);
	init_items(map, map->width, map->height);
	fd = open(argv[1], O_RDONLY);
	insert_into_map(fd, map);
	close(fd);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 32*map->width, 32*map->height, "so_long");
	read_map(mlx, map, mlx_win);
	mlx_loop(mlx);
}

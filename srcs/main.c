/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:41:55 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/23 19:00:08 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_items(t_map *map, int width, int height)
{
	int	i;

	i = 0;
	map->wall_path = "/home/danijosepereira/42/42-cursus/so_long/textures/wall.xpm";
	map->floor_path = "/home/danijosepereira/42/42-cursus/so_long/textures/floor.xpm";
	map->exit_path = "/home/danijosepereira/42/42-cursus/so_long/textures/exit.xpm";
	map->player_path = "/home/danijosepereira/42/42-cursus/so_long/textures/player.xpm";
	map->item_path = "/home/danijosepereira/42/42-cursus/Cursus/so_long/textures/item.xpm";
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
	check_width(map, fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	check_height(map, fd);
	close(fd);
	init_items(map, map->width, map->height);
	fd = open(argv[1], O_RDONLY);
	insert_into_map(fd, map);
	close(fd);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 64*map->width, 64*map->height, "so_long");
	read_map(mlx, map, mlx_win);
	mlx_loop(mlx);
}

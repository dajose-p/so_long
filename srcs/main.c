/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:41:55 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/20 19:56:56 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_items(t_map *map)
{
	map->wall_path = "/home/danijosepereira/42/42-cursus/so_long/textures/wall.xpm";
	map->floor_path = "/home/danijosepereira/42/42-cursus/so_long/textures/floor.xpm";
	map->exit_path = "/home/danijosepereira/42/42-cursus/so_long/textures/exit.xpm";
	map->player_path = "/home/danijosepereira/42/42-cursus/so_long/textures/player.xpm";
	map->item_path = "/home/danijosepereira/42/42-cursus/so_long/textures/item.xpm";
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
	init_items(map);
	fd = open(argv[1], O_RDONLY);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 32*get_line_width(fd, argv[1]), 32*count_lines(fd, map), "so_long");
	fd = open(argv[1], O_RDONLY);
	read_map(mlx, map, fd, argv[1], mlx_win);
	mlx_loop(mlx);
}

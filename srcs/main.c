/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:41:55 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/23 20:39:34 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_items(t_map *map, int width, int height)
{
	int	i;

	i = 0;
	map->player.count = 0;
    	map->item.count = 0;
    	map->exit.count = 0;
	map->wall_path = "textures/wall.xpm";
	map->floor_path = "textures/floor.xpm";
	map->exit_path = "textures/exit.xpm";
	map->player_path = "textures/player.xpm";
	map->item_path = "textures/item.xpm";
	map->full_map = malloc((height + 1) * sizeof(char *));
	while (i < height)
	{
		map->full_map[i] = malloc((width + 2) * sizeof(char));
		i++;
	}
}

int main(int argc, char **argv)
{
	int	fd;
	t_map *map;

	(void)argc;
	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	map->mlx = mlx_init();
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
	map->mlx_win = mlx_new_window(map->mlx, 64*map->width, 64*map->height, "so_long");
	read_map(map->mlx, map, map->mlx_win);
	mlx_loop(map->mlx);
}

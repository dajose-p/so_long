/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:41:55 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/18 20:30:23 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_items(t_map *map, int count_lines)
{
	map->items = malloc(count_lines * sizeof(t_map));
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
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 32*13, 32*count_lines(fd, map), "so_long");
	fd = open(argv[1], O_RDONLY);
	init_items(map, count_lines(fd, map));
	fd = open(argv[1], O_RDONLY);
	read_map(mlx, map, fd, argv[1], mlx_win);
	mlx_loop(mlx);
}

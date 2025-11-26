/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:41:55 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/25 22:06:07 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	fd_error(void)
{
	perror("so_long");
	exit(1);
}

void	init_items(t_map *map)
{
	int	i;

	i = 0;
	map->wall_path = "textures/wall.xpm";
	map->floor_path = "textures/floor.xpm";
	map->exit_path = "textures/exit.xpm";
	map->player_path = "textures/player.xpm";
	map->item_path = "textures/item.xpm";
	map->full_map = malloc((map->height + 1) * sizeof(char *));
}

void	main_flow(t_map *map, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		fd_error();
	check_width(map, fd);
	close(fd);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		fd_error();
	check_height(map, fd);
	close(fd);
	init_items(map);
	fd = open(path, O_RDONLY);
	insert_into_map(fd, map);
	close(fd);
	read_map(map);
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, 64 * map->width, 64 * map->height,
			"so_long");
	draw_map(map);
	key_call(map);
	mlx_loop(map->mlx);
}

int	check_ext(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i] == '.')
		{
			if (file[i + 1] == 'b' && file[i + 2] == 'e' && file[i + 3] == 'r')
			{
				i += 4;
				if (file[i] == '\0')
					return (1);
			}
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		ft_printf("Incorrect input\nUsage: ./so_long <map_file.ber>\n");
		return (0);
	}
	if (!check_ext(argv[1]))
	{
		ft_printf("Map extension must be .ber\n");
		return (0);
	}
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (0);
	main_flow(map, argv[1]);
}

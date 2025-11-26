/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:03:36 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/26 19:03:44 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->full_map[i][j] && map->full_map[i][j] != '\n')
		{
			if (map->full_map[i][j] == 'P')
			{
				map->player.count++;
				map->player.x = j;
				map->player.y = i;
			}
			j++;
		}
		i++;
	}
}

void	check_walls(t_map *map)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < map->height)
	{
		flag = wall_in_check(map, i, flag);
		i++;
	}
	if (flag != 0)
		ft_error(map, "Map is not surrounded by walls");
}

void	check_exit(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->full_map[i][j] && map->full_map[i][j] != '\n')
		{
			if (map->full_map[i][j] == 'E')
			{
				map->exit.count++;
				map->exit.x = j;
				map->exit.y = i;
			}
			j++;
		}
		i++;
	}
}

void	check_items(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->full_map[i][j] && map->full_map[i][j] != '\n')
		{
			if (map->full_map[i][j] == 'C')
				map->item.count++;
			j++;
		}
		i++;
	}
}

void	check_map(t_map *map, char **dup_map)
{
	check_rect(map);
	check_walls(map);
	check_player(map);
	check_items(map);
	check_exit(map);
	if (!*dup_map)
		ft_error(map, "Map?");
	check_path(dup_map, map->player.x, map->player.y);
	if (map->player.count > 1)
		ft_error(map, "Map has more than one player");
	if (map->item.count < 1)
		ft_error(map, "Map has less than one item");
	if (map->exit.count > 1)
		ft_error(map, "Map has more than one exit");
	check_flood_path(map, dup_map);
}

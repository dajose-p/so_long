/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:38:09 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/23 19:21:20 by danjose-         ###   ########.fr       */
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
		while (map->full_map[i][j] != '\n')
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

void    check_walls(t_map *map)
{
        int     i;
	int	j;
	int	flag;

        i = 0;
	j = 0;
	flag = 0;
	while(i < map->height)
	{
		j = 0;
		while (map->full_map[i][j] != '\n')
		{
			if (i == 0 || i == map->height - 1)
			{
				if (map->full_map[i][j] != '1')
					flag = -1;
			}
			else if (j == 0 || j == map->width - 1)
			{
				if (map->full_map[i][j] != '1')
					flag = -1;
			}
			j++;
		}
		i++;
	}
	if (flag != 0)
		ft_error(map, "Map is not a rectangle");
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
		while (map->full_map[i][j] != '\n')
		{
			if (map->full_map[i][j] == 'E')
				map->exit.count++;
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
		while (map->full_map[i][j] != '\n')
		{
			if (map->full_map[i][j] == 'C')
				map->item.count++;
			j++;
		}
		i++;
	}
}

void    check_map(t_map *map, char **dup_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	check_rect(map);
	check_walls(map);
	check_player(map);
	check_items(map);
	check_exit(map);
	check_path(dup_map, map->player.x, map->player.y);
	if (map->player.count > 1)
		ft_error(map, "Map has more than one player");
	if (map->item.count < 1)
		ft_error(map, "Map has less than one item");
	if (map->exit.count > 1)
		ft_error(map, "Map has more than one exit");
	while (i < map->height)
	{
		j = 0;
		printf("%s\n", dup_map[i]);
		while (dup_map[i][j] != '\n')
		{
			if (dup_map[i][j] != '1' && dup_map[i][j] != 'T')
				ft_error(map, "Map does not have a valid path");
			j++;
		}
		i++;
	}
}

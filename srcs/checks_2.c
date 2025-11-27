/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:03:55 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/26 19:39:45 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_rect(t_map *map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (i < map->height)
	{
		j = 0;
		c = 0;
		while (map->full_map[i][j] && map->full_map[i][j] != '\n')
		{
			j++;
			c++;
		}
		if (c != map->width)
			ft_error(map, "Map is not a rectancle");
		i++;
	}
}

void	check_path(char **dup_map, int x, int y)
{
	char	wall;
	char	tar;
	char	col;

	wall = '1';
	tar = '0';
	col = 'T';
	if (dup_map[y][x] == wall || dup_map[y][x] == col)
		return ;
	if (dup_map[y][x] != tar && dup_map[y][x] != 'P' && dup_map[y][x] != 'E'
		&& dup_map[y][x] != 'C')
		return ;
	dup_map[y][x] = col;
	check_path(dup_map, x + 1, y);
	check_path(dup_map, x - 1, y);
	check_path(dup_map, x, y + 1);
	check_path(dup_map, x, y - 1);
	return ;
}

void	check_flood_path(t_map *map, char **dup_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (dup_map[i][j] && dup_map[i][j] != '\n')
		{
			if (dup_map[i][j] == 'C' || dup_map[i][j] == 'E')
			{
				free_dup(dup_map);
				ft_error(map, "Map does not have a valid path");
			}
			j++;
		}
		i++;
	}
}

int	wall_in_check(t_map *map, int i, int flag)
{
	int	j;

	j = 0;
	while (map->full_map[i][j] != '\n' && map->full_map[i][j])
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
	return (flag);
}

int	check_charset(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->full_map[i][j] != '\n' && map->full_map[i][j])
		{
			c = map->full_map[i][j];
			if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P'
				&& c != 0 && c != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:20:49 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/23 18:04:13 by danjose-         ###   ########.fr       */
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
		while (map->full_map[i][j] != '\n')
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

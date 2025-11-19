/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:38:09 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/18 20:34:14 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_player(char *line, t_map *map)
{
	int	i;
	
	i = 0;
	while(line[i] != '\n')
	{
		if (line[i] == 'E')
			map->player.count++;
		i++;
	}
	return (i);
}

void    check_walls(char *line, int line_count, t_map *map, int max)
{
        int     i;

        i = 0;
        while (line[i] != '\n')
        {
                if (line[i] != '1' && (i == 0 || (size_t)i == (ft_strlen(line) - 1)))
                        ft_error(map, "Map needs to be surrounded by walls");
                else if (line[i] != '1' && (line_count == max || line_count == 1))
                        ft_error(map, "Map needs to be surrounded by walls");
                i++;
        }
}

int	check_exit(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] == 'E')
			map->exit.count++;
		i++;
	}
	return (i);
}

int	check_items(char *line, int pos, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] == 'C')
			map->items[pos].count++;
		i++;
	}
	return (i);
}

void    check_map(char *line, t_map *map, int line_count, int max)
{
        int     i;
	int	j;
	int	counter;
        i = 0;
	j = 0;
	counter = 0;
        check_walls(line, line_count, map, max);
	map->exit.x = check_exit(line, map);
	map->exit.y = i;
	map->items[i].x = check_items(line, i, map);
	map->items[i].y = i;
	map->player.x = check_player(line, map);
	map->player.y = i;
	if (map->exit.count > 1)
		ft_error(map, "Map has more than one exit");
	if (map->player.count > 1)
		ft_error(map, "Map has more than one initial position");
}

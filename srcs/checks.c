/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:38:09 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/08 17:07:36 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    check_walls(char *line, int line_count)
{
        int     i;
        int     count;

        i = 0;
        while (line[i] != '\n')
        {
                if (line[i] != '1' && (i == 0 || i == (ft_strlen(line) - 1))
                        ft_error(map, "Map needs to be surrounded by walls");
                else if (line[i] != '1' && (line_count == max || line_count == 1))
                        ft_error(map, "Map needs to be surrounded by walls");
                i++;
        }
}

void	check_exit(char *line, t_map *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\n')
	{
		if (line[i] == 'E')
			map->exit->count++;
		i++;
	}
	return (i);
}

void	check_items(char *line, int pos)
{
	int	i;
	int	count;

	while (line[i] != '\n')
	{
		if (line[i] == 'C')
			map->item[pos]->count++;
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
        check_walls(line, line_count);
	map->exit->x = check_exit(line, map);
	map->exit->y = i;
	map->items[i]->x = check_items(line, i);
	map->items[i]->y = i;
	map->player->x = check_player(line);
	map->player->y = check_player(line);
	if (map->exit->count > 1)
		ft_error(map, "Map has more than one exit");
	if (map->player->count > 1)
		ft_error(map, "Map has more than one initial position");
	while (map->items[j] < line_count)
	{
		j++;
		counter += map->items[i]->count;
	}
	if (counter < 1)
		ft_error(map, "Map has no objects");
}

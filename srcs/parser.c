/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:45:57 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/07 22:39:17 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_walls(char *line, int line_count)
{
	int	i;
	int	count;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '1' && (i == 0 || i == (ft_strlen(line) - 1))
			ft_error(map, "Map needs to be surrounded by walls");
		else if (line[i] != '1' && (line_count == max || line_count == 1))
			ft_error(map, "Map needs to be surrounded by walls");
		i++;
	}
	return (i);
}

void	check_map(char *line, t_map *map, int line_count, int max)
{
	map->walls = check_walls(line, line_count);
}

void	read_map(t_map *map, int fd, char *path)
{
	char	*line;
	int	line_count;
	int	max;

	line_count = check_lines(fd);
	max = line_count;
	close(fd);
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line_count > 0)
	{
		check_map(line, map, line_count);
		free(line);
		line = get_next_line(fd);
		line_count--;
	}
}

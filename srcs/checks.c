/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:38:09 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/19 10:58:34 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_player(t_map *map, int fd)
{
	int	i;
	char	*line;
	
	i = 0;
	line = get_next_line(fd);
	while(line)
	{
		while (line[i] != '\n')
		{
			if (line[i] == 'E')
			map->player.count++;
			i++;
		}
		free(line);
		line = get_next_line(fd);
		if (*line == '\0')
			free(line);
	}
	close(fd);
}

void    check_walls(t_map *map, int fd)
{
        int     i;
	int	line_count;
	char	*line;

        i = 0;
	line_count = 0;
	line = get_next_line(fd);
        while (line)
        {
		while (line[i] != '\n')
		{
			if (line[i] != '1' && (i == 0 || (size_t)i == (ft_strlen(line) - 1)))
                        	ft_error(map, "Map needs to be surrounded by walls");
               		else if (line[i] != '1' && (line_count == 5 || line_count == 1))
                        	ft_error(map, "Map needs to be surrounded by walls");
                	i++;
		}
		line_count++;
		free(line);
		line = get_next_line(fd);
		if (*line == '\0')
			free(line);
        }
	close(fd);
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

int	check_items(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] == 'C')
			map->item.count++;
		i++;
	}
	return (0);
}

void    check_map(t_map *map, int fd, char *path)
{
        check_walls(map, fd);
	fd = open(path, O_RDONLY);
	check_player(map, fd);
}

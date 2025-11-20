/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:38:09 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/20 19:57:00 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_player(t_map *map, char *line)
{
	int	i;
	
	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] == 'E')
		map->player.count++;
		i++;
	}
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
               		else if (line[i] != '1' && (line_count == 4 || line_count == 1))
                        	ft_error(map, "Map needs to be surrounded by walls");
                	i++;
		}
		line_count++;
		free(line);
		line = get_next_line(fd);
		if (*line == '\0')
		{
			free(line);
			line = NULL;
		}
        }
	close(fd);
}

int	check_exit(t_map *map, char *line)
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

int	check_items(t_map *map, char *line)
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
        char	*line;

	check_walls(map, fd);
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		check_player(map, line);
		check_items(map, line);
		check_exit(map, line);
		free(line);
		line = get_next_line(fd);
		if (*line == '\0')
		{
			free(line);
			line = NULL;
		}
	}

	close(fd);
}

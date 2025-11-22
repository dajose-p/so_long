/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:42:32 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/22 18:45:55 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error(t_map *map, char *msg)
{
	free(map);
	ft_printf("Error\n");
	perror(msg);
	exit(1);
}

int     count_lines(char *path)
{
        char    *line;
	int	i;
	int	fd;

        fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
        while (line)
        {
		i++;
                free(line);
                line = get_next_line(fd);
		if (*line == '\0')
		{
			free(line);
			line = NULL;
		}
        }
	close(fd);
	return (i);
}

int	get_line_width(char *path)
{
	char	*line;
	int	i;
	int	fd;
	
	i = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		while (line[i] != '\n')
			i++;
		free(line);
		line = get_next_line(fd);
		if (*line == '\0')
		{
			free(line);
			line = NULL;
		}
	}
	close(fd);
	return (i);
}

void	insert_into_map(char *path, t_map *map)
{
	int	i;
	char	*line;
	int	fd;
	
	i = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		map->full_map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		if (*line == '\0')
		{
			free(line);
			line = NULL;
		}
		i++;
	}
	close(fd);
}

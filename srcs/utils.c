/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:42:32 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/26 17:54:34 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_dup(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_error(t_map *map, char *msg)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->full_map[i]);
		i++;
	}
	free(map->full_map);
	free(map);
	ft_printf("Error\n%s\n", msg);
	exit(1);
}

void	check_width(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line && line[i] && line[i] != '\n')
		i++;
	map->width = i;
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			return ;
		free(line);
	}
}

void	check_height(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = "1";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
		{
			map->height = i;
			return ;
		}
		free(line);
		i++;
	}
}

void	insert_into_map(int fd, t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	line = "1";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			return ;
		map->full_map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	map->full_map[i] = NULL;
}

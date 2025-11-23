/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:42:32 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/23 16:31:23 by danjose-         ###   ########.fr       */
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

void	check_width(t_map *map, int fd)
{
	char	*line;
	int	i;

	i = 0;
	line = get_next_line(fd);
	while (line[i] != '\n')
		i++;
	free(line);
	map->width = i;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			return ;
		}
	}
}

void	check_height(t_map *map, int fd)
{
	char	*line;
	int	i;

	i = 0;
	line = "1";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			map->height = i;
			return ;
		}
		free(line);
		i++;
	}
}

void	insert_into_map(int fd, t_map *map)
{
	int	i;
	char	*line;
	
	i = 0;
	line = "1";
	while(line)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			return ;
		}
		map->full_map[i] = ft_strdup(line);
		free(line);
		i++;
	}
}

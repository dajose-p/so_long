/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:42:32 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/22 20:22:17 by danjose-         ###   ########.fr       */
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

void	check_size(t_map *map, int fd)
{
	char	*line;
	int	h;
	int	w;

	h = 0;
	w = 0;
	line = "1";
	while (line)
	{
		line = get_next_line(fd);
		h++;
		while (line[w] != '\0')
			w++;
		if (!line[0])
			break;
		free(line);
	}
	map->height = h;
	map->width = w;
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
		map->full_map[i] = ft_strdup(line);
		i++;
		if (!line)
			break;
		free(line);
	}
}

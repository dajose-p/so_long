/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:42:32 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/18 20:28:32 by danjose-         ###   ########.fr       */
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

int     count_lines(int fd, t_map *map)
{
        char    *line;
	int	length;
	int	last_length;
	int	i;

        line = get_next_line(fd);
	length = 0;
	last_length = 0;
	i = 0;
        while (line)
        {
		length = get_line_width(line);
		last_length = length;
		if (last_length != length)
			ft_error(map, "Map is not a rectangle");
		last_length = length;
		i++;
                free(line);
                line = get_next_line(fd);
		if (*line == '\0')
			return (i);
        }
	return (i);
	close(fd);
}

int	get_line_width(char *line)
{
	int	i;
	
	i = 0;
	while (line[i] != '\n')
		i++;
	return (i);
}

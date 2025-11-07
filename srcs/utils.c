/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:42:32 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/07 22:28:31 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(t_map *map, char *msg)
{
	free(map);
	ft_printf("Error\n");
	perror(msg);
	exit(1);
}

int     count_lines(int fd)
{
        char    *line;

        line = get_next_line(fd);
        while (line)
        {
		length = get_line_width(line);
		if (last_length != length)
			ft_error("Map is not a rectangle");
		last_length = length;
		i++;
                free(line);
                line = get_next_line(fd);
        }
}

int	get_line_width(char *line)
{
	int	i;
	while (line[i] != '\n')
		i++;
	return (i);
}

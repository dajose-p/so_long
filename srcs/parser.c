/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:45:57 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/08 16:39:00 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

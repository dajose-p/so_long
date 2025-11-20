/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:42:32 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/20 19:52:06 by danjose-         ###   ########.fr       */
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

int     count_lines(int fd)
{
        char    *line;
	int	i;

        line = get_next_line(fd);
	i = 0;
        while (line)
        {
		i++;
                free(line);
                line = get_next_line(fd);
		if (*line == '\0')
			return (i);
        }
	return (i);
	close(fd);
}

int	get_line_width(int fd, char *path)
{
	char	*line;
	int	i;
	
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

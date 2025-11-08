/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:38:09 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/08 16:41:20 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    check_walls(char *line, int line_count)
{
        int     i;
        int     count;

        i = 0;
        while (line[i] != '\n')
        {
                if (line[i] != '1' && (i == 0 || i == (ft_strlen(line) - 1))
                        ft_error(map, "Map needs to be surrounded by walls");
                else if (line[i] != '1' && (line_count == max || line_count == 1))
                        ft_error(map, "Map needs to be surrounded by walls");
                i++;
        }
}

void	check_exit(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\n')
	{
		if (line[i] = 'E')
			count++;
		i++;
	}

}

void    check_map(char *line, t_map *map, int line_count, int max)
{
        int     i;

        i = 0;
        check_walls(line, line_count);
        i += check_exit(line);
}


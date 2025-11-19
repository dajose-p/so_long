/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:43:32 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/19 10:57:24 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

struct	s_coords
{
	int	x;
	int	y;
	int	count;
};

typedef struct	s_map
{
	int	walls;
	int	floor;
	struct	s_coords	player;
	struct	s_coords	item;
	struct	s_coords	exit;
}	t_map;

void    check_map(t_map *map, int fd, char *path);
int    check_items(char *line, t_map *map);
int    check_exit(char *line, t_map *map);
void    check_walls(t_map *map, int fd);
void    read_map(void * mlx, t_map *map, int fd, char *path, void *mlx_win);
void    ft_error(t_map *map, char *msg);
int     count_lines(int fd, t_map *map);
int     get_line_width(char *line);
void     check_player(t_map *map, int fd);
int     get_line_width(char *line);

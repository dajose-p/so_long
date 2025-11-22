/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:43:32 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/22 19:59:17 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

struct	s_coords
{
	int	count;
};

typedef struct	s_map
{
	int	width;
	int	height;
	int	walls;
	int	floor;
	char	*wall_path;
	char	*floor_path;
	char	*item_path;
	char	*exit_path;
	char	*player_path;
	void	*wall_img;
	void	*floor_img;
	void	*item_img;
	void	*exit_img;
	void	*player_img;
	struct	s_coords	player;
	struct	s_coords	item;
	struct	s_coords	exit;
	char	**full_map;
}	t_map;

void    check_map(t_map *map);
void    check_items(t_map *map);
void    check_exit(t_map *map);
void    check_walls(t_map *map);
void	check_size(t_map *map, int fd);
void    read_map(void * mlx, t_map *map, void *mlx_win);
void    ft_error(t_map *map, char *msg);
void     check_player(t_map *map);
void	insert_into_map(int fd, t_map *map);
void	init_items(t_map *map, int width, int height);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:43:32 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/26 19:31:07 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

enum				e_keys
{
	W_UP = 119,
	ARR_UP = 65362,
	A_LEFT = 97,
	ARR_LEFT = 65361,
	S_DOWN = 115,
	ARR_DOWN = 65364,
	D_RIGHT = 100,
	ARR_RIGHT = 65363,
	ESC = 65307
};

struct				s_coords
{
	int				count;
	int				x;
	int				y;
};

typedef struct s_map
{
	void			*mlx;
	void			*mlx_win;
	int				width;
	int				height;
	int				walls;
	int				floor;
	char			*wall_path;
	char			*floor_path;
	char			*item_path;
	char			*exit_path;
	char			*player_path;
	void			*wall_img;
	void			*floor_img;
	void			*item_img;
	void			*exit_img;
	void			*player_img;
	struct s_coords	player;
	struct s_coords	item;
	struct s_coords	exit;
	char			**full_map;
	int				moves;
}					t_map;

void				check_map(t_map *map, char **dup_map);
void				check_items(t_map *map);
void				check_exit(t_map *map);
void				check_walls(t_map *map);
void				check_width(t_map *map, int fd);
void				check_height(t_map *map, int fd);
void				check_rect(t_map *map);
void				check_path(char **dup_map, int x, int y);
void				check_exit_draw(t_map *map);
void				check_flood_path(t_map *map, char **dup_map);
void				read_map(t_map *map);
void				draw_map(t_map *map);
void				ft_error(t_map *map, char *msg);
void				check_player(t_map *map);
void				insert_into_map(int fd, t_map *map);
void				init_items(t_map *map);
int					key_kandler(int keycode, t_map *map);
void				key_call(t_map *map);
void				move_up(t_map *map, int i, int j);
void				move_left(t_map *map, int i, int j);
void				move_down(t_map *map, int i, int j);
void				move_right(t_map *map, int i, int j);
void				free_dup(char **map);
int					wall_in_check(t_map *map, int i, int flag);
int					check_charset(t_map *map);

#endif

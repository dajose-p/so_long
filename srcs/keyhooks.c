/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:36:42 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/25 02:48:49 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	clean_and_exit(t_map *map)
{
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_image(map->mlx, map->wall_img);
	mlx_destroy_image(map->mlx, map->exit_img);
	mlx_destroy_image(map->mlx, map->floor_img);
	mlx_destroy_image(map->mlx, map->player_img);
	mlx_destroy_image(map->mlx, map->item_img);
	return (0);
}

void	check_exit_draw(t_map *map)
{
	if (map->item.count == 0 && map->exit.x == map->player.x
		&& map->exit.y == map->player.y)
	{
		ft_printf("Well done!\n");
		exit(clean_and_exit(map));
	}
}

int	hook_exit(t_map *map)
{
	exit(clean_and_exit(map));
}

int	key_handler(int keycode, t_map *map)
{
	int	i;
	int	j;

	i = map->player.y;
	j = map->player.x;
	if (keycode == ESC)
		exit(clean_and_exit(map));
	if (keycode == W_UP || keycode == ARR_UP)
		move_up(map, i, j);
	if (keycode == A_LEFT || keycode == ARR_LEFT)
		move_left(map, i, j);
	if (keycode == S_DOWN || keycode == ARR_DOWN)
		move_down(map, i, j);
	if (keycode == D_RIGHT || keycode == ARR_RIGHT)
		move_right(map, i, j);
	if (map->item.count == 0)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->exit_img, 64
			* map->exit.x, 64 * map->exit.y);
	check_exit_draw(map);
	return (0);
}

void	key_call(t_map *map)
{
	mlx_key_hook(map->mlx_win, key_handler, map);
	mlx_hook(map->mlx_win, 17, 1L << 0, hook_exit, map);
}

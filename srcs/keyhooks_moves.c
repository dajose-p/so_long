/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 02:14:35 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/25 02:16:57 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_up(t_map *map, int i, int j)
{
	if (map->full_map[i - 1][j] == '1')
		return ;
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->floor_img, 64
		* map->player.x, 64 * map->player.y);
	if (map->full_map[i - 1][j] == 'C')
	{
		map->item.count--;
		map->full_map[i - 1][j] = '0';
		ft_printf("You grabbed an item\n");
	}
	map->player.y--;
	map->moves++;
	ft_printf("Total moves: %i. Moved UP\n", map->moves);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->player_img, 64
		* map->player.x, 64 * map->player.y);
}

void	move_left(t_map *map, int i, int j)
{
	if (map->full_map[i][j - 1] == '1')
		return ;
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->floor_img, 64
		* map->player.x, 64 * map->player.y);
	if (map->full_map[i][j - 1] == 'C')
	{
		map->item.count--;
		map->full_map[i][j - 1] = '0';
		ft_printf("You grabbed an item\n");
	}
	map->player.x--;
	map->moves++;
	ft_printf("Total moves: %i. Moved LEFT\n", map->moves);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->player_img, 64
		* map->player.x, 64 * map->player.y);
}

void	move_down(t_map *map, int i, int j)
{
	if (map->full_map[i + 1][j] == '1')
		return ;
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->floor_img, 64
		* map->player.x, 64 * map->player.y);
	if (map->full_map[i + 1][j] == 'C')
	{
		map->item.count--;
		map->full_map[i + 1][j] = '0';
		ft_printf("You grabbed an item\n");
	}
	map->player.y++;
	map->moves++;
	ft_printf("Total moves: %i. Moved DOWN\n", map->moves);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->player_img, 64
		* map->player.x, 64 * map->player.y);
}

void	move_right(t_map *map, int i, int j)
{
	if (map->full_map[i][j + 1] == '1')
		return ;
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->floor_img, 64
		* map->player.x, 64 * map->player.y);
	if (map->full_map[i][j + 1] == 'C')
	{
		map->item.count--;
		map->full_map[i][j + 1] = '0';
		ft_printf("You grabbed an item\n");
	}
	map->player.x++;
	map->moves++;
	ft_printf("Total moves: %i. Moved RIGHT\n", map->moves);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->player_img, 64
		* map->player.x, 64 * map->player.y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:41:55 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/08 18:24:20 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"

void	init_items(t_map map)
{

}

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_stack *map;

	(void)mlx_win;
	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	while (
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, get_win_width(map), get_win_height(map), "Hello");
	mlx_loop(mlx);
}

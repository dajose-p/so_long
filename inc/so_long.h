/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:43:32 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/08 16:50:49 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"

struct	s_coords
{
	int	x;
	int	y;
	int	count;
}

typedef struct	s_map
{
	int	walls;
	int	floor;
	struct	s_coords	player->x;
	struct	s_coords	player->y;
	struct	s_coords	(*items)->x;
	struct	s_coords	(*items)->y;
	struct	s_coords	exit->x;
	struct	s_coords	exit->y;
}	t_map

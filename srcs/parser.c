/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:45:57 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/19 10:59:23 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_line(char *line, void *mlx, void *win, int line_count)
{
	int	img_width;
	int	img_height;
	void	*img;
	char	*img_path;
	int i;

	img_path = "/home/danijosepereira/42/42-cursus/so_long/textures/wall.xpm";
	i = 0;
	img = mlx_xpm_file_to_image(mlx, img_path, &img_width, &img_height);
	while (line[i] != '\n')
	{
		if (line[i] == '1')
			mlx_put_image_to_window(mlx, win, img, 32*i, line_count*32);
		i++;
	}
}

void	read_map(void *mlx, t_map *map, int fd, char *path, void *mlx_win)
{
	(void)mlx;
	(void)mlx_win;
	close(fd);
	fd = open(path, O_RDONLY);
	check_map(map, fd, path);
	fd = open(path, O_RDONLY);
}

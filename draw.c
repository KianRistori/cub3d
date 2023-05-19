/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:41:37 by kristori          #+#    #+#             */
/*   Updated: 2023/05/19 11:39:04 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void mlx_fill_square(int x, int y, int size, int color, t_image buffer)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			ft_mlx_pixel_put(x + i, y + j, color, buffer);
		}
	}
}

void	ft_draw_minimap(t_program *prog, t_image buffer)
{
	for (int y = 0; prog->map[y] != NULL; y++)
	{
		for (int x = 0; prog->map[y][x] != '\0'; x++)
		 {
			if (prog->map[y][x] == '1')
				mlx_fill_square(x * 5, y * 5, 5, 0XFFFFFF, buffer);
			else if (prog->map[y][x] == '0')
				mlx_fill_square(x * 5, y * 5, 5, 0x000000, buffer);
			else if (prog->map[y][x] == 'C')
				mlx_fill_square(x * 5, y * 5, 5, 0x0000FF00, buffer);
			else if (prog->map[y][x] == 'O')
				mlx_fill_square(x * 5, y * 5, 5, 0xFF8686, buffer);
		}
	}
	mlx_fill_square(prog->player.pos_y * 5, prog->player.pos_x * 5, 5, 0x647B94, buffer);
}

void	ft_draw_vertical_line(int x, int y1, int y2, int color, t_image buffer)
{
	int y;

	for (y = y1; y <= y2; y++)
		ft_mlx_pixel_put(x, y, color, buffer);
}

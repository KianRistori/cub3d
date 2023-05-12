/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:41:37 by kristori          #+#    #+#             */
/*   Updated: 2023/05/12 10:43:28 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void mlx_fill_square(t_program *prog, int x, int y, int size, int color)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			ft_mlx_pixel_put(prog, x + i, y + j, color);
		}
	}
}

void	ft_draw_minimap(t_program *prog)
{
	for (int y = 0; prog->map[y] != NULL; y++)
	{
		for (int x = 0; prog->map[y][x] != '\0'; x++)
		 {
			if (prog->map[y][x] == '1')
				mlx_fill_square(prog, x * 5, y * 5, 5, 0XFFFFFF);
			else if (prog->map[y][x] == '0')
				mlx_fill_square(prog, x * 5, y * 5, 5, 0x000000);
		}
	}
	mlx_fill_square(prog, prog->player.pos_y * 5, prog->player.pos_x * 5, 5, 0x647B94);
}

void	ft_draw_vertical_line(t_program *prog, int x, int y1, int y2, int color)
{
	int y;

	for (y = y1; y <= y2; y++)
		ft_mlx_pixel_put(prog, x, y, color);
}

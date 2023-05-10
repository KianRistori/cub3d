/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:41:37 by kristori          #+#    #+#             */
/*   Updated: 2023/05/08 10:12:10 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void mlx_fill_square(t_program *prog, int x, int y, int size, int color)
{
    for (int i = 0; i < size; i++) 
	{
        for (int j = 0; j < size; j++) 
		{
            mlx_pixel_put(prog->mlx, prog->window.reference, x + i, y + j, color);
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
                mlx_fill_square(prog, x * 5, y * 5, 5, 0xFFFFFF);
            else if (prog->map[y][x] == '0')
                mlx_fill_square(prog, x * 5, y * 5, 5, 0x000000);
        }
    }
	mlx_fill_square(prog, prog->player.pos_y * 5, prog->player.pos_x * 5, 5, 0x000000FF);
}

void	ft_draw_line(t_program *prog, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX;
	double deltaY = endY - beginY;

	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
		mlx_pixel_put(prog->mlx, prog->window.reference, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}

void	ft_draw_vertical_line(void *mlx_ptr, void *win_ptr, int x, int y1, int y2, int color)
{
	int y;

	for (y = y1; y <= y2; y++)
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
}

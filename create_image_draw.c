/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image_draw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:22:26 by kristori          #+#    #+#             */
/*   Updated: 2023/05/24 14:53:13 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_ceiling(t_program *program, t_image buffer)
{
	int	y;
	int	x;

	y = 0;
	while (y < SCREEN_H / 2)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			ft_mlx_pixel_put(x, y, ft_create_trgb(0, program->ceiling), buffer);
			x++;
		}
		y++;
	}
}

void	ft_draw_floor(t_program *program, t_image buffer)
{
	int	y;
	int	x;

	y = SCREEN_H / 2;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			ft_mlx_pixel_put(x, y, ft_create_trgb(0, program->floor), buffer);
			x++;
		}
		y++;
	}
}

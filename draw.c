/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:41:37 by kristori          #+#    #+#             */
/*   Updated: 2023/05/24 11:43:15 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mlx_fill_square(int x, int y, int color, t_image buffer)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			ft_mlx_pixel_put(x + i, y + j, color, buffer);
			j++;
		}
		i++;
	}
}

void	ft_draw_minimap(t_program *prog, t_image buffer)
{
	int	x;
	int	y;

	y = 0;
	while (prog->map[y] != NULL)
	{
		x = 0;
		while (prog->map[y][x] != '\0')
		{
			if (prog->map[y][x] == '1' || prog->map[y][x] == 'A')
				mlx_fill_square(x * 5, y * 5, 0XFFFFFF, buffer);
			else if (prog->map[y][x] == '0')
				mlx_fill_square(x * 5, y * 5, 0x000000, buffer);
			else if (prog->map[y][x] == 'C')
				mlx_fill_square(x * 5, y * 5, 0x0000FF00, buffer);
			else if (prog->map[y][x] == 'O')
				mlx_fill_square(x * 5, y * 5, 0xFF8686, buffer);
			x++;
		}
		y++;
	}
	mlx_fill_square(prog->player.pos_y * 5,
		prog->player.pos_x * 5, 0x647B94, buffer);
}

void	ft_put_texture_pixel(int x, int y, t_image texture, t_image buffer)
{
	char	*dst;
	char	*src;

	if (x >= 0 && x < buffer.width && y >= 0 && y < buffer.height)
	{
		dst = buffer.pixels + (y * buffer.line_size
				+ x * (buffer.bits_per_pixel / 8));
		src = texture.pixels + ((y % texture.height) * texture.line_size
				+ (x % texture.width) * (texture.bits_per_pixel / 8));
		*(unsigned int *)dst = *(unsigned int *)src;
	}
}

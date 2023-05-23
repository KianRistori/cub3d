/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:09:44 by kristori          #+#    #+#             */
/*   Updated: 2023/05/23 11:17:24 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	ft_new_image(void *mlx, int width, int height)
{
	t_image	img;

	img.reference = mlx_new_image(mlx, width, height);
	img.size.x = width;
	img.size.x = height;
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}

void	ft_create_image(t_program *program, t_image buffer)
{
	//Disegna il cielo
	for (int y = 0; y < SCREEN_H / 2; y++)
	{
		for (int x = 0; x < SCREEN_W; x++)
			ft_mlx_pixel_put(x, y, ft_create_trgb(0, program->ceiling), buffer);
	}
	// Disegna il terreno
	for (int y = SCREEN_H / 2; y < SCREEN_H; y++)
	{
		for (int x = 0; x < SCREEN_W; x++)
			ft_mlx_pixel_put(x, y, ft_create_trgb(0, program->floor), buffer);
	}
	for (int x = 0; x < SCREEN_W; x++)
	{
		double cameraX = 2 * x / (double)SCREEN_W - 1;
		double rayDirX = program->player.dir_x + program->player.plane_x * cameraX;
		double rayDirY = program->player.dir_y + program->player.plane_y * cameraX;
		int mapX = (int)program->player.pos_x;
		int mapY = (int)program->player.pos_y;

		double sideDistX;
		double sideDistY;

		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side;
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (program->player.pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - program->player.pos_x) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (program->player.pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - program->player.pos_y) * deltaDistY;
		}
		int wallDirection;

		while(hit == 0)
		{
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}

			if(program->map[mapX][mapY] == '1' || program->map[mapX][mapY] == 'C' || program->map[mapX][mapY] == 'A')
				hit = 1;
			if (side == 0 && stepX == -1)
				wallDirection = 0;
			else if (side == 0 && stepX == 1)
				wallDirection = 1;
			else if (side == 1 && stepY == -1)
				wallDirection = 2;
			else if (side == 1 && stepY == 1)
				wallDirection = 3;
		}
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		int lineHeight = (int)(SCREEN_H / perpWallDist);

		int drawStart = -lineHeight / 2 + SCREEN_H / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + SCREEN_H / 2;
		if (drawEnd >= SCREEN_H)
			drawEnd = SCREEN_H - 1;

  		double wallX;
     	if (side == 0)
			wallX = program->player.pos_y + perpWallDist * rayDirY;
      	else
			wallX = program->player.pos_x + perpWallDist * rayDirX;
      	wallX -= floor((wallX));

		t_image texture;

		if (program->map[mapX][mapY] == '1' && wallDirection == 0)
			texture = program->textures[0];
		if (program->map[mapX][mapY] == '1' && wallDirection == 1)
			texture = program->textures[1];
		if (program->map[mapX][mapY] == '1' && wallDirection == 2)
			texture = program->textures[2];
		if (program->map[mapX][mapY] == '1' && wallDirection == 3)
			texture = program->textures[3];
		if (program->map[mapX][mapY] == 'C')
			texture = program->door;
		if (program->map[mapX][mapY] == 'A')
			texture = program->wall_sprite[program->frame_wall % 9];
		int texX = wallX * (texture.width);
     	if(side == 0 && rayDirX > 0)
			texX = texture.width - texX - 1;
      	if(side == 1 && rayDirY < 0)
			texX = texture.width - texX - 1;

		double step = 1.0 * texture.height / lineHeight;
		double texPos = (drawStart - SCREEN_H / 2 + lineHeight / 2) * step;
		for (int y = drawStart; y <= drawEnd; y++)
		{
			int texY = (int)texPos & (texture.height - 1);
			texPos += step;
			int color = ft_get_texture_pixel(texture, texX, texY);
			if(side == 1)
				color = ft_add_shade(color, 0.5);
			ft_mlx_pixel_put(x, y, color, buffer);
		}
	}
	ft_draw_minimap(program, buffer);
}

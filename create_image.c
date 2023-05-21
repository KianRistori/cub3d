/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:09:44 by kristori          #+#    #+#             */
/*   Updated: 2023/05/21 18:03:42 by kristori         ###   ########.fr       */
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
		double cameraX = 2 * x / (double)SCREEN_W - 1; //x-coordinate in camera space
		double rayDirX = program->player.dir_x + program->player.plane_x * cameraX;
		double rayDirY = program->player.dir_y + program->player.plane_y * cameraX;
		//which box of the map we're in
		int mapX = (int)program->player.pos_x;
		int mapY = (int)program->player.pos_y;

		//length of ray from current position to next x or y-side
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
		//perform DDA
		while(hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
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
			//Check if ray has hit a wall
			if(program->map[mapX][mapY] == '1' || program->map[mapX][mapY] == 'C')
				hit = 1;
		}

		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(SCREEN_H / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + SCREEN_H / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + SCREEN_H / 2;
		if (drawEnd >= SCREEN_H)
			drawEnd = SCREEN_H - 1;

  		double wallX; //where exactly the wall was hit
     	if (side == 0) 
			wallX = program->player.pos_y + perpWallDist * rayDirY;
      	else           
			wallX = program->player.pos_x + perpWallDist * rayDirX;
      	wallX -= floor((wallX));

		t_image texture;
		
		if (program->map[mapX][mapY] == '1')
			texture = program->textures[0];
		if (program->map[mapX][mapY] == 'C')
			texture = program->door;
		// if (program->map[mapX][mapY] == 'O')
		// 	color = 0x301086;
		int texX = wallX * (texture.width);
     	if(side == 0 && rayDirX > 0)
			texX = texture.width - texX - 1;
      	if(side == 1 && rayDirY < 0)
			texX = texture.width - texX - 1;
		
		double step = 1.0 * texture.height / lineHeight;
		double texPos = (drawStart - SCREEN_H / 2 + lineHeight / 2) * step;
		for (int y = drawStart; y <= drawEnd; y++)
		{
			int texY = (int)texPos & (texture.height - 1); // Calculate the corresponding y-coordinate on the texture
			texPos += step;
			int color = ft_get_texture_pixel(texture, texX, texY); // Get the color from the texture
			if(side == 1)
				color = ft_add_shade(color, 0.5);
			ft_mlx_pixel_put(x, y, color, buffer); // Draw the pixel on the screen
		}
	}
	ft_draw_minimap(program, buffer);
}
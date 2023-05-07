/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:42:10 by kristori          #+#    #+#             */
/*   Updated: 2023/05/07 16:16:04 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_input(int key, void *param)
{
	t_program	*program;

	program = (t_program *)param;
	mlx_clear_window(program->mlx, program->window.reference);
	printf("key: %d\n", key);
	printf("player posx: %f, player posy: %f\n", program->player.pos_x, program->player.pos_y);
	printf("player dirx: %f, player diry: %f\n", program->player.dir_x, program->player.dir_y);
	printf("player planex: %f, player planey: %f\n", program->player.plane_x, program->player.plane_y);
	// //speed modifiers
	program->move_speed = 0.2;
	double rotSpeed = 0.1;
	if (key == 119) // W
	{
		if(program->map[(int)(program->player.pos_x + program->player.dir_x * program->move_speed)][(int)(program->player.pos_y)] == '0')
			program->player.pos_x += program->player.dir_x * program->move_speed;
		if(program->map[(int)(program->player.pos_x)][(int)(program->player.pos_y + program->player.dir_y * program->move_speed)] == '0')
			program->player.pos_y += program->player.dir_y * program->move_speed;
	}
	// if (key == 97) // A
	// {
	// }
	if (key == 115) // S
	{
		if(program->map[(int)(program->player.pos_x - program->player.dir_x * program->move_speed)][(int)(program->player.pos_y)] == '0')
			program->player.pos_x -= program->player.dir_x * program->move_speed;
		if(program->map[(int)(program->player.pos_x)][(int)(program->player.pos_y - program->player.dir_y * program->move_speed)] == '0')
			program->player.pos_y -= program->player.dir_y * program->move_speed;
	}
	// if (key == 100) // D
	// {
	// }
	if (key == 65363) // Right Arrow
	{
		double oldDirX = program->player.dir_x;
		program->player.dir_x = program->player.dir_x * cos(-rotSpeed) - program->player.dir_y * sin(-rotSpeed);
		program->player.dir_y = oldDirX * sin(-rotSpeed) + program->player.dir_y * cos(-rotSpeed);
		double oldPlaneX = program->player.plane_x;
		program->player.plane_x = program->player.plane_x * cos(-rotSpeed) - program->player.plane_y * sin(-rotSpeed);
		program->player.plane_y = oldPlaneX * sin(-rotSpeed) + program->player.plane_y * cos(-rotSpeed);
	}
	if (key == 65361) // Left Arrow
	{
		double oldDirX = program->player.dir_x;
		program->player.dir_x = program->player.dir_x * cos(rotSpeed) - program->player.dir_y * sin(rotSpeed);
		program->player.dir_y = oldDirX * sin(rotSpeed) + program->player.dir_y * cos(rotSpeed);
		double oldPlaneX = program->player.plane_x;
		program->player.plane_x = program->player.plane_x * cos(rotSpeed) - program->player.plane_y * sin(rotSpeed);
		program->player.plane_y = oldPlaneX * sin(rotSpeed) + program->player.plane_y * cos(rotSpeed);
	}
	ft_exit(program, key);
	return (0);
}

int	ft_update(void *param)
{
	t_program	*program;

	program = (t_program *)param;
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
			if(program->map[mapX][mapY] > '0')
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
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + SCREEN_H / 2;
		if(drawEnd >= SCREEN_H) drawEnd = SCREEN_H - 1;

		int color;

		if (program->map[mapX][mapY] == '1')
			color = 0x00FF0000;

		//give x and y sides different brightness
		if(side == 1)
			color = ft_add_shade(color, 0.5);

		//draw the pixels of the stripe as a vertical line
		ft_draw_vertical_line(program->mlx, program->window.reference, x, drawStart, drawEnd, color);
	}
	return (0);
}

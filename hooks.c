/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:42:10 by kristori          #+#    #+#             */
/*   Updated: 2023/05/23 15:10:22 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mouse(int x, int y, t_program *program)
{
	(void)y;
	int old_mouse_x = program->mouse_pos.x;
	program->mouse_pos.x = x;
	program->rot_speed = 0.01;
	if (program->mouse_pos.x < SCREEN_W/7)
		program->rot_speed = 0.06;
	if (program->mouse_pos.x > SCREEN_W/7*6)
		program->rot_speed = 0.06;
	if (old_mouse_x < program->mouse_pos.x) // Right Arrow
	{
		double oldDirX = program->player.dir_x;
		program->player.dir_x = program->player.dir_x * cos(-program->rot_speed) - program->player.dir_y * sin(-program->rot_speed);
		program->player.dir_y = oldDirX * sin(-program->rot_speed) + program->player.dir_y * cos(-program->rot_speed);
		double oldPlaneX = program->player.plane_x;
		program->player.plane_x = program->player.plane_x * cos(-program->rot_speed) - program->player.plane_y * sin(-program->rot_speed);
		program->player.plane_y = oldPlaneX * sin(-program->rot_speed) + program->player.plane_y * cos(-program->rot_speed);
	}
	if (old_mouse_x > program->mouse_pos.x) // Left Arrow
	{
		double oldDirX = program->player.dir_x;
		program->player.dir_x = program->player.dir_x * cos(program->rot_speed) - program->player.dir_y * sin(program->rot_speed);
		program->player.dir_y = oldDirX * sin(program->rot_speed) + program->player.dir_y * cos(program->rot_speed);
		double oldPlaneX = program->player.plane_x;
		program->player.plane_x = program->player.plane_x * cos(program->rot_speed) - program->player.plane_y * sin(program->rot_speed);
		program->player.plane_y = oldPlaneX * sin(program->rot_speed) + program->player.plane_y * cos(program->rot_speed);
	}
	return (0);
}

int	ft_input(int key, void *param)
{
	t_program	*program;

	program = (t_program *)param;
	program->rot_speed = 0.1;
	if (key == 119) // W
	{
		if (program->map[(int)(program->player.pos_x + program->player.dir_x * program->move_speed)][(int)(program->player.pos_y)] == '0')
			program->player.pos_x += program->player.dir_x * program->move_speed;
		else if (program->map[(int)(program->player.pos_x + program->player.dir_x * program->move_speed)][(int)(program->player.pos_y)] == 'O')
			program->player.pos_x += program->player.dir_x * program->move_speed;
		if (program->map[(int)(program->player.pos_x)][(int)(program->player.pos_y + program->player.dir_y * program->move_speed)] == '0')
			program->player.pos_y += program->player.dir_y * program->move_speed;
		else if (program->map[(int)(program->player.pos_x)][(int)(program->player.pos_y + program->player.dir_y * program->move_speed)] == 'O')
			program->player.pos_y += program->player.dir_y * program->move_speed;
	}
	if (key == 97) // A
	{
		if(program->map[(int)(program->player.pos_x - program->player.dir_y * program->move_speed)][(int)(program->player.pos_y)] == '0')
			program->player.pos_x -= program->player.dir_y * program->move_speed;
		else if (program->map[(int)(program->player.pos_x - program->player.dir_y * program->move_speed)][(int)(program->player.pos_y)] == 'O')
			program->player.pos_x -= program->player.dir_y * program->move_speed;
		if (program->map[(int)(program->player.pos_x)][(int)(program->player.pos_y + program->player.dir_x * program->move_speed)] == '0')
			program->player.pos_y += program->player.dir_x * program->move_speed;
		else if (program->map[(int)(program->player.pos_x)][(int)(program->player.pos_y + program->player.dir_x * program->move_speed)] == 'O')
			program->player.pos_y += program->player.dir_x * program->move_speed;
	}
	if (key == 115) // S
	{
		if(program->map[(int)(program->player.pos_x - program->player.dir_x * program->move_speed)][(int)(program->player.pos_y)] == '0')
			program->player.pos_x -= program->player.dir_x * program->move_speed;
		else if(program->map[(int)(program->player.pos_x - program->player.dir_x * program->move_speed)][(int)(program->player.pos_y)] == 'O')
			program->player.pos_x -= program->player.dir_x * program->move_speed;
		if(program->map[(int)(program->player.pos_x)][(int)(program->player.pos_y - program->player.dir_y * program->move_speed)] == '0')
			program->player.pos_y -= program->player.dir_y * program->move_speed;
		else if(program->map[(int)(program->player.pos_x)][(int)(program->player.pos_y - program->player.dir_y * program->move_speed)] == 'O')
			program->player.pos_y -= program->player.dir_y * program->move_speed;
	}
	if (key == 100) // D
	{
		if(program->map[(int)(program->player.pos_x + program->player.dir_y * program->move_speed)][(int)(program->player.pos_y)] == '0')
			program->player.pos_x += program->player.dir_y * program->move_speed;
		else if(program->map[(int)(program->player.pos_x + program->player.dir_y * program->move_speed)][(int)(program->player.pos_y)] == 'O')
			program->player.pos_x += program->player.dir_y * program->move_speed;
		if(program->map[(int)(program->player.pos_x)][(int)(program->player.pos_y - program->player.dir_x * program->move_speed)] == '0')
			program->player.pos_y -= program->player.dir_x * program->move_speed;
		else if(program->map[(int)(program->player.pos_x)][(int)(program->player.pos_y - program->player.dir_x * program->move_speed)] == 'O')
			program->player.pos_y -= program->player.dir_x * program->move_speed;
	}
	if (key == 65363) // Right Arrow
	{
		double oldDirX = program->player.dir_x;
		program->player.dir_x = program->player.dir_x * cos(-program->rot_speed) - program->player.dir_y * sin(-program->rot_speed);
		program->player.dir_y = oldDirX * sin(-program->rot_speed) + program->player.dir_y * cos(-program->rot_speed);
		double oldPlaneX = program->player.plane_x;
		program->player.plane_x = program->player.plane_x * cos(-program->rot_speed) - program->player.plane_y * sin(-program->rot_speed);
		program->player.plane_y = oldPlaneX * sin(-program->rot_speed) + program->player.plane_y * cos(-program->rot_speed);
	}
	if (key == 65361) // Left Arrow
	{
		double oldDirX = program->player.dir_x;
		program->player.dir_x = program->player.dir_x * cos(program->rot_speed) - program->player.dir_y * sin(program->rot_speed);
		program->player.dir_y = oldDirX * sin(program->rot_speed) + program->player.dir_y * cos(program->rot_speed);
		double oldPlaneX = program->player.plane_x;
		program->player.plane_x = program->player.plane_x * cos(program->rot_speed) - program->player.plane_y * sin(program->rot_speed);
		program->player.plane_y = oldPlaneX * sin(program->rot_speed) + program->player.plane_y * cos(program->rot_speed);
	}
	if (program->map[(int)(program->player.pos_x + program->player.dir_x * program->move_speed)][(int)(program->player.pos_y)] == 'C')
		mlx_string_put(program->mlx, program->window.reference, SCREEN_W / 2, SCREEN_H / 2, 0xFFFFFF, "Press F to open the door");
	else if (program->map[(int)(program->player.pos_x + program->player.dir_x * program->move_speed)][(int)(program->player.pos_y)] == 'O')
		mlx_string_put(program->mlx, program->window.reference, SCREEN_W / 2, SCREEN_H / 2, 0xFFFFFF, "Press F to close the door");
	if (key == 102) //F
	{
		if (program->map[(int)(program->player.pos_x + program->player.dir_x * program->move_speed)][(int)(program->player.pos_y)] == 'C')
		{
			program->map[(int)(program->player.pos_x + program->player.dir_x * program->move_speed)][(int)(program->player.pos_y)] = 'O';
			ft_create_image(program, program->buffer);
			mlx_put_image_to_window(program->mlx, program->window.reference, program->buffer.reference, 0, 0);
		}
		else if (program->map[(int)(program->player.pos_x + program->player.dir_x * program->move_speed)][(int)(program->player.pos_y)] == 'O')
		{
			program->map[(int)(program->player.pos_x + program->player.dir_x * program->move_speed)][(int)(program->player.pos_y)] = 'C';
			ft_create_image(program, program->buffer);
			mlx_put_image_to_window(program->mlx, program->window.reference, program->buffer.reference, 0, 0);
		}
	}
	ft_exit(program, key);
	return (0);
}

int	ft_update(t_program *program)
{
	program->frame++;
	if (!(program->frame % 50))
		program->frame_wall++;
	ft_create_image(program, program->buffer);
	mlx_put_image_to_window(program->mlx, program->window.reference, program->buffer.reference, 0, 0);
	return (0);
}

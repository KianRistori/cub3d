/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:42:10 by kristori          #+#    #+#             */
/*   Updated: 2023/05/12 11:46:22 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_input(int key, void *param)
{
	t_program	*program;

	program = (t_program *)param;
	mlx_clear_window(program->mlx, program->window.reference);
	ft_create_image(program);
	mlx_put_image_to_window(program->mlx, program->window.reference, program->buffer.reference, 0, 0);
	printf("key: %d\n", key);
	printf("player posx: %f, player posy: %f\n", program->player.pos_x, program->player.pos_y);
	printf("player dirx: %f, player diry: %f\n", program->player.dir_x, program->player.dir_y);
	printf("player planex: %f, player planey: %f\n", program->player.plane_x, program->player.plane_y);
	if (key == 119) // W
	{
		if(program->map[(int)(program->player.pos_x + program->player.dir_x * program->move_speed)][(int)(program->player.pos_y)] == '0')
			program->player.pos_x += program->player.dir_x * program->move_speed;
		if(program->map[(int)(program->player.pos_x)][(int)(program->player.pos_y + program->player.dir_y * program->move_speed)] == '0')
			program->player.pos_y += program->player.dir_y * program->move_speed;
	}
	if (key == 97) // A
	{
		if(program->map[(int)(program->player.pos_x - program->player.dir_y * program->move_speed)][(int)(program->player.pos_y)] == '0')
			program->player.pos_x -= program->player.dir_y * program->move_speed;
		if(program->map[(int)(program->player.pos_x)][(int)(program->player.pos_y + program->player.dir_x * program->move_speed)] == '0')
			program->player.pos_y += program->player.dir_x * program->move_speed;
	}
	if (key == 115) // S
	{
		if(program->map[(int)(program->player.pos_x - program->player.dir_x * program->move_speed)][(int)(program->player.pos_y)] == '0')
			program->player.pos_x -= program->player.dir_x * program->move_speed;
		if(program->map[(int)(program->player.pos_x)][(int)(program->player.pos_y - program->player.dir_y * program->move_speed)] == '0')
			program->player.pos_y -= program->player.dir_y * program->move_speed;
	}
	if (key == 100) // D
	{
		if(program->map[(int)(program->player.pos_x + program->player.dir_y * program->move_speed)][(int)(program->player.pos_y)] == '0')
			program->player.pos_x += program->player.dir_y * program->move_speed;
		if(program->map[(int)(program->player.pos_x)][(int)(program->player.pos_y - program->player.dir_x * program->move_speed)] == '0')
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
	ft_exit(program, key);
	return (0);
}

// int	ft_update(void *param)
// {
// 	t_program	*program;

// 	program = (t_program *)param;

// 	return (0);
// }

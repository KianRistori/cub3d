/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:37:39 by kristori          #+#    #+#             */
/*   Updated: 2023/05/24 10:58:58 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_w(t_program *program)
{
	if (program->map[(int)(program->player.pos_x
			+ program->player.dir_x * program->move_speed)]
				[(int)(program->player.pos_y)] == '0')
		program->player.pos_x += program->player.dir_x * program->move_speed;
	else if (program->map[(int)(program->player.pos_x
			+ program->player.dir_x * program->move_speed)]
				[(int)(program->player.pos_y)] == 'O')
		program->player.pos_x += program->player.dir_x * program->move_speed;
	if (program->map[(int)(program->player.pos_x)]
			[(int)(program->player.pos_y + program->player.dir_y
				* program->move_speed)] == '0')
		program->player.pos_y += program->player.dir_y * program->move_speed;
	else if (program->map[(int)(program->player.pos_x)]
			[(int)(program->player.pos_y + program->player.dir_y
				* program->move_speed)] == 'O')
		program->player.pos_y += program->player.dir_y * program->move_speed;
	return (0);
}

int	ft_key_a(t_program *program)
{
	if (program->map[(int)(program->player.pos_x
			- program->player.dir_y * program->move_speed)]
				[(int)(program->player.pos_y)] == '0')
		program->player.pos_x -= program->player.dir_y * program->move_speed;
	else if (program->map[(int)(program->player.pos_x
			- program->player.dir_y * program->move_speed)]
				[(int)(program->player.pos_y)] == 'O')
		program->player.pos_x -= program->player.dir_y * program->move_speed;
	if (program->map[(int)(program->player.pos_x)]
			[(int)(program->player.pos_y + program->player.dir_x
				* program->move_speed)] == '0')
		program->player.pos_y += program->player.dir_x * program->move_speed;
	else if (program->map[(int)(program->player.pos_x)]
			[(int)(program->player.pos_y + program->player.dir_x
				* program->move_speed)] == 'O')
		program->player.pos_y += program->player.dir_x * program->move_speed;
	return (0);
}

int	ft_key_s(t_program *program)
{
	if (program->map[(int)(program->player.pos_x
			- program->player.dir_x * program->move_speed)]
				[(int)(program->player.pos_y)] == '0')
		program->player.pos_x -= program->player.dir_x * program->move_speed;
	else if (program->map[(int)(program->player.pos_x
			- program->player.dir_x * program->move_speed)]
				[(int)(program->player.pos_y)] == 'O')
		program->player.pos_x -= program->player.dir_x * program->move_speed;
	if (program->map[(int)(program->player.pos_x)]
			[(int)(program->player.pos_y - program->player.dir_y
				* program->move_speed)] == '0')
		program->player.pos_y -= program->player.dir_y * program->move_speed;
	else if (program->map[(int)(program->player.pos_x)]
			[(int)(program->player.pos_y - program->player.dir_y
				* program->move_speed)] == 'O')
		program->player.pos_y -= program->player.dir_y * program->move_speed;
	return (0);
}

int	ft_key_d(t_program *program)
{
	if (program->map[(int)(program->player.pos_x
			+ program->player.dir_y * program->move_speed)]
				[(int)(program->player.pos_y)] == '0')
		program->player.pos_x += program->player.dir_y * program->move_speed;
	else if (program->map[(int)(program->player.pos_x
			+ program->player.dir_y * program->move_speed)]
				[(int)(program->player.pos_y)] == 'O')
		program->player.pos_x += program->player.dir_y * program->move_speed;
	if (program->map[(int)(program->player.pos_x)]
			[(int)(program->player.pos_y - program->player.dir_x
				* program->move_speed)] == '0')
		program->player.pos_y -= program->player.dir_x * program->move_speed;
	else if (program->map[(int)(program->player.pos_x)]
			[(int)(program->player.pos_y - program->player.dir_x
				* program->move_speed)] == 'O')
		program->player.pos_y -= program->player.dir_x * program->move_speed;
	return (0);
}

int	ft_key_f(t_program *program)
{
	if (program->map[(int)(program->player.pos_x
			+ program->player.dir_x * program->move_speed)]
				[(int)(program->player.pos_y)] == 'C')
	{
		program->map[(int)(program->player.pos_x + program->player.dir_x
				* program->move_speed)][(int)(program->player.pos_y)] = 'O';
		ft_create_image(program, program->buffer);
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->buffer.reference, 0, 0);
	}
	else if (program->map[(int)(program->player.pos_x
			+ program->player.dir_x * program->move_speed)]
				[(int)(program->player.pos_y)] == 'O')
	{
		program->map[(int)(program->player.pos_x + program->player.dir_x
				* program->move_speed)][(int)(program->player.pos_y)] = 'C';
		ft_create_image(program, program->buffer);
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->buffer.reference, 0, 0);
	}
	return (0);
}

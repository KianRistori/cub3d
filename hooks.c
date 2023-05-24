/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:42:10 by kristori          #+#    #+#             */
/*   Updated: 2023/05/24 11:04:48 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mouse(int x, int y, t_program *program)
{
	int	old_mouse_x;

	(void)y;
	old_mouse_x = program->mouse_pos.x;
	program->mouse_pos.x = x;
	program->rot_speed = 0.01;
	if (program->mouse_pos.x < SCREEN_W / 7)
		program->rot_speed = 0.06;
	if (program->mouse_pos.x > SCREEN_W / 7 * 6)
		program->rot_speed = 0.06;
	if (old_mouse_x < program->mouse_pos.x)
		ft_key_right_arrow(program);
	if (old_mouse_x > program->mouse_pos.x)
		ft_key_left_arrow(program);
	return (0);
}

int	ft_input(int key, t_program *program)
{
	program->rot_speed = 0.1;
	if (key == 119)
		ft_key_w(program);
	if (key == 97)
		ft_key_a(program);
	if (key == 115)
		ft_key_s(program);
	if (key == 100)
		ft_key_d(program);
	if (key == 65363)
		ft_key_right_arrow(program);
	if (key == 65361)
		ft_key_left_arrow(program);
	ft_draw_key_press(program);
	if (key == 102)
		ft_key_f(program);
	ft_exit(program, key);
	return (0);
}

int	ft_update(t_program *program)
{
	program->frame++;
	if (!(program->frame % 50))
		program->frame_wall++;
	ft_create_image(program, program->buffer);
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->buffer.reference, 0, 0);
	return (0);
}

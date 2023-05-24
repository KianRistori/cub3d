/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:43:23 by kristori          #+#    #+#             */
/*   Updated: 2023/05/24 11:01:33 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_left_arrow(t_program *program)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = program->player.dir_x;
	program->player.dir_x = program->player.dir_x
		* cos(program->rot_speed) - program->player.dir_y
		* sin(program->rot_speed);
	program->player.dir_y = old_dir_x * sin(program->rot_speed)
		+ program->player.dir_y * cos(program->rot_speed);
	old_plane_x = program->player.plane_x;
	program->player.plane_x = program->player.plane_x
		* cos(program->rot_speed) - program->player.plane_y
		* sin(program->rot_speed);
	program->player.plane_y = old_plane_x * sin(program->rot_speed)
		+ program->player.plane_y * cos(program->rot_speed);
	return (0);
}

int	ft_key_right_arrow(t_program *program)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = program->player.dir_x;
	program->player.dir_x = program->player.dir_x
		* cos(-program->rot_speed) - program->player.dir_y
		* sin(-program->rot_speed);
	program->player.dir_y = old_dir_x * sin(-program->rot_speed)
		+ program->player.dir_y * cos(-program->rot_speed);
	old_plane_x = program->player.plane_x;
	program->player.plane_x = program->player.plane_x
		* cos(-program->rot_speed) - program->player.plane_y
		* sin(-program->rot_speed);
	program->player.plane_y = old_plane_x * sin(-program->rot_speed)
		+ program->player.plane_y * cos(-program->rot_speed);
	return (0);
}

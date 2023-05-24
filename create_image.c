/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:09:44 by kristori          #+#    #+#             */
/*   Updated: 2023/05/24 11:05:22 by kristori         ###   ########.fr       */
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

static void	ft_init_ray(t_program *program, t_raycast *ray, int x)
{
	ray->camera_x = 2 * x / (double)SCREEN_W - 1;
	ray->ray_dir_x = program->player.dir_x
		+ program->player.plane_x * ray->camera_x;
	ray->ray_dir_y = program->player.dir_y
		+ program->player.plane_y * ray->camera_x;
	ray->map_x = (int)program->player.pos_x;
	ray->map_y = (int)program->player.pos_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void	ft_ray_wall_direction(t_raycast *ray)
{
	if (ray->side == 0 && ray->step_x == -1)
		ray->wall_direction = 0;
	else if (ray->side == 0 && ray->step_x == 1)
		ray->wall_direction = 1;
	else if (ray->side == 1 && ray->step_y == -1)
		ray->wall_direction = 2;
	else if (ray->side == 1 && ray->step_y == 1)
		ray->wall_direction = 3;
}

void	ft_draw_key_press(t_program *program)
{
	if (program->map[(int)(program->player.pos_x
			+ program->player.dir_x * program->move_speed)]
				[(int)(program->player.pos_y)] == 'C')
		mlx_string_put(program->mlx, program->window.reference,
			SCREEN_W / 2, SCREEN_H / 2, 0xFFFFFF, "Press F to open the door");
	else if (program->map[(int)(program->player.pos_x
			+ program->player.dir_x * program->move_speed)]
				[(int)(program->player.pos_y)] == 'O')
		mlx_string_put(program->mlx, program->window.reference,
			SCREEN_W / 2, SCREEN_H / 2, 0xFFFFFF, "Press F to close the door");
}

void	ft_create_image(t_program *program, t_image buffer)
{
	t_raycast	ray;
	int			x;

	ft_draw_ceiling(program, buffer);
	ft_draw_floor(program, buffer);
	x = 0;
	while (x < SCREEN_W)
	{
		ft_init_ray(program, &ray, x);
		ft_ray_dir(program, &ray);
		ft_ray_hit(program, &ray);
		ft_ray_side(program, &ray);
		ft_ray_init_texture(program, &ray);
		ft_ray_draw_vertical(&ray, buffer, x);
		x++;
	}
	ft_draw_minimap(program, buffer);
}

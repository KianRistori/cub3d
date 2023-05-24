/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:54:31 by kristori          #+#    #+#             */
/*   Updated: 2023/05/23 17:04:24 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ray_dir(t_program *program, t_raycast *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (program->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - program->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (program->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - program->player.pos_y)
			* ray->delta_dist_y;
	}
}

void	ft_ray_hit(t_program *program, t_raycast *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (program->map[ray->map_x][ray->map_y] == '1'
			|| program->map[ray->map_x][ray->map_y] == 'C'
				|| program->map[ray->map_x][ray->map_y] == 'A')
			ray->hit = 1;
		ft_ray_wall_direction(ray);
	}
}

void	ft_ray_side(t_program *program, t_raycast *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->line_height = (int)(SCREEN_H / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + SCREEN_H / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + SCREEN_H / 2;
	if (ray->draw_end >= SCREEN_H)
		ray->draw_end = SCREEN_H - 1;
	if (ray->side == 0)
		ray->wall_x = program->player.pos_y
			+ ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = program->player.pos_x
			+ ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor((ray->wall_x));
}

void	ft_ray_init_texture(t_program *program, t_raycast *ray)
{
	if (program->map[ray->map_x][ray->map_y] == '1' && ray->wall_direction == 0)
		ray->texture = program->textures[0];
	if (program->map[ray->map_x][ray->map_y] == '1' && ray->wall_direction == 1)
		ray->texture = program->textures[1];
	if (program->map[ray->map_x][ray->map_y] == '1' && ray->wall_direction == 2)
		ray->texture = program->textures[2];
	if (program->map[ray->map_x][ray->map_y] == '1' && ray->wall_direction == 3)
		ray->texture = program->textures[3];
	if (program->map[ray->map_x][ray->map_y] == 'C')
		ray->texture = program->door;
	if (program->map[ray->map_x][ray->map_y] == 'A')
		ray->texture = program->wall_sprite[program->frame_wall % 9];
}

void	ft_ray_draw_vertical(t_raycast *ray, t_image buffer, int x)
{
	int	color;
	int	y;

	y = ray->draw_start;
	ray->tex_x = ray->wall_x * (ray->texture.width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_x = ray->texture.width - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->tex_x = ray->texture.width - ray->tex_x - 1;
	ray->step = 1.0 * ray->texture.height / ray->line_height;
	ray->tex_pos = (ray->draw_start - SCREEN_H / 2 + ray->line_height / 2)
		* ray->step;
	while (y <= ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (ray->texture.height - 1);
		ray->tex_pos += ray->step;
		color = ft_get_texture_pixel(ray->texture, ray->tex_x, ray->tex_y);
		if (ray->side == 1)
			color = ft_add_shade(color, 0.5);
		ft_mlx_pixel_put(x, y, color, buffer);
		y++;
	}
}

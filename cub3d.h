/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:11:12 by kristori          #+#    #+#             */
/*   Updated: 2023/05/24 11:04:34 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>

# define SCREEN_W 1280
# define SCREEN_H 960

#define TEXTURE_W 64
#define TEXTURE_H 64

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_window {
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_player;

typedef struct s_color {
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_raycast {
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		wall_direction;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
	t_image texture;
}		t_raycast;

typedef struct s_program {
	void		*mlx;
	char		**map;
	char		*map_path;
	double		move_speed;
	double		rot_speed;
	int			mouse_move;
	int			frame;
	int			frame_wall;
	t_image		*textures;
	t_image		*wall_sprite;
	t_image		door;
	t_image		buffer;
	t_color		floor;
	t_color		ceiling;
	t_window	window;
	t_player	player;
	t_vector	mouse_pos;
	char		**path;
}				t_program;

int		ft_arr_cmp(char *str, char **set);
int		ft_map_parsing(char *map, t_program *prog);
char	**ft_strjoin_map(char **map, char *str);
int		ft_validate_map(char **map, t_program *prog);
t_window	ft_new_window(t_program *program, char *name);
void	ft_exit(t_program *program, int key);
int		ft_close(void *param);
void	ft_free_all(t_program *program);
void	ft_draw_line(t_program *prog, int beginX, int beginY, int endX, int endY, int color);
void	ft_draw_vertical_line(int x, int y1, int y2, int color, t_image buffer);
void ft_mlx_put_image_pixel(int x, int drawStart, int drawEnd, t_image texture, t_image buffer);
void	ft_draw_minimap(t_program *prog, t_image buffer);
int	ft_input(int key, t_program *program);
int		ft_update(t_program *program);
int		ft_add_shade(int color, float factor);
int		ft_create_trgb(int t, t_color color);
void	ft_create_image(t_program *program, t_image buffer);
void	ft_mlx_pixel_put(int x, int y, int color, t_image buffer);
t_image	ft_new_image(void *mlx, int width, int height);
int		ft_mouse(int x, int y, t_program *program);
t_image	ft_get_image(t_program *prog, char *path);
void	ft_load_textures(t_program *prog);
int	ft_get_texture_pixel(t_image texture, int x, int y);
void	ft_put_texture_pixel(int x, int y, t_image texture, t_image buffer);
void	ft_init_wall_sprite(t_program *prog);
void	ft_free(char **str);
void	ft_draw_ceiling(t_program *program, t_image buffer);
void	ft_draw_floor(t_program *program, t_image buffer);
void	ft_ray_dir(t_program *program, t_raycast *ray);
void	ft_ray_hit(t_program *program, t_raycast *ray);
void	ft_ray_side(t_program *program, t_raycast *ray);
void	ft_ray_init_texture(t_program *program, t_raycast *ray);
void	ft_ray_draw_vertical(t_raycast *ray, t_image buffer, int x);
void	ft_ray_wall_direction(t_raycast *ray);

int	ft_key_w(t_program *program);
int	ft_key_a(t_program *program);
int	ft_key_s(t_program *program);
int	ft_key_d(t_program *program);
int	ft_key_f(t_program *program);
int	ft_key_left_arrow(t_program *program);
int	ft_key_right_arrow(t_program *program);
void	ft_draw_key_press(t_program *program);

#endif

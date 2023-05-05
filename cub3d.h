/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:11:12 by kristori          #+#    #+#             */
/*   Updated: 2023/05/05 11:45:24 by kristori         ###   ########.fr       */
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

// risoluzione
# define SCREEN_W 640
# define SCREEN_H 480

# define mapWidth 24
# define mapHeight 24

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
	char		*path;
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

typedef struct s_program {
	void		*mlx;
	char		**map;
	char		*map_path;
	double		time;
	double		old_time;
	double		move_speed;
	t_image		**textures;
	t_color		floor;
	t_color		ceiling;
	t_window	window;
	t_player	player;
}				t_program;

int		ft_arr_cmp(char *str, char **set);
int		ft_map_parsing(char *map, t_program *prog);
char	**ft_strjoin_map(char **map, char *str);
int		ft_validate_map(char **map, t_program *prog);
t_window	ft_new_window(t_program *program, char *name);
void	ft_exit(t_program *program, int key);
int	ft_close(void *param);
void	ft_free_all(t_program *program);
void	ft_draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color);
void	ft_draw_vertical_line(void *mlx_ptr, void *win_ptr, int x, int y1, int y2, int color);
int	ft_input(int key, void *param);
int	ft_update(void *param);
#endif
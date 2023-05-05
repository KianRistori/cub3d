/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:11:12 by kristori          #+#    #+#             */
/*   Updated: 2023/05/05 11:11:19 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

// risoluzione
# define SCREEN_W 640
# define SCREEN_H 480

// Field Of View
# define FOV 0.66

// Pi
# define PI 3.14159

// passo di movimento e rotazione
# define MOVSPEED 0.1
# define ROTSPEED 0.05

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
    double  pos_x;
    double  pos_y;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;
}               t_player;

typedef struct s_color {
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_program {
	void		*mlx;
	char		**map;
	char		*map_path;
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
#endif
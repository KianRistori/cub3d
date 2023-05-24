/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:07:21 by javellis          #+#    #+#             */
/*   Updated: 2023/05/24 11:39:40 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "cub3d.h"

static int	ft_path_find(char **map, int *err, int x, int y)
{
	if (ft_strlen(map[x]) < (size_t)y || x <= 0 || y <= 0
		|| map[x][y] == ' ' || map[x][y] == 10)
	{
		*err = 1;
		return (0);
	}
	map[x][y] = '1';
	if (map[x + 1][y] != '1')
		ft_path_find(map, err, x + 1, y);
	if (map[x - 1][y] != '1')
		ft_path_find(map, err, x - 1, y);
	if (map[x][y + 1] != '1')
		ft_path_find(map, err, x, y + 1);
	if (map[x][y - 1] != '1')
		ft_path_find(map, err, x, y - 1);
	return (0);
}

static int	ft_charcmp(char c, char *set)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (set[i])
	{
		if (c == set[i])
			flag = 1;
		i++;
	}
	return (flag);
}

static t_player	ft_data_init(double dir_x,
	double dir_y, double plane_x, double plane_y)
{
	t_player	player;

	player.dir_x = dir_x;
	player.dir_y = dir_y;
	player.plane_x = plane_x;
	player.plane_y = plane_y;
	return (player);
}

static void	ft_initial_position_player(char **map, int i,
	int j, t_program *prog)
{
	if (map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'E' || map[i][j] == 'W')
	{
		if (map[i][j] == 'N')
			prog->player = ft_data_init(-1, 0, 0, 0.66);
		else if (map[i][j] == 'W')
			prog->player = ft_data_init(0, -1, -0.66, 0);
		else if (map[i][j] == 'S')
			prog->player = ft_data_init(1, 0, 0, -0.66);
		else if (map[i][j] == 'E')
			prog->player = ft_data_init(0, 1, 0.66, 0);
		prog->player.pos_x = i + 0.01;
		prog->player.pos_y = j + 0.01;
		map[i][j] = '0';
	}
}

int	ft_validate_map(char **map, t_program *prog)
{
	int		index[2];
	char	*set;
	char	**new_map;
	int		err;

	set = "01CONSEWA \n";
	index[0] = 0;
	err = 0;
	while (map[index[0]])
	{
		index[1] = 0;
		while (map[index[0]][index[1]])
		{
			ft_initial_position_player(map, index[0], index[1], prog);
			if (!ft_charcmp(map[index[0]][index[1]++], set))
				return (0);
		}
		index[0]++;
	}
	new_map = ft_mapdup(map);
	ft_path_find(new_map, &err, prog->player.pos_x, prog->player.pos_y);
	ft_free(new_map);
	if (err)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:07:21 by javellis          #+#    #+#             */
/*   Updated: 2023/05/07 16:21:23 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**ft_mapdup(char **tab)
{
	char	**temp;
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (tab[i])
		i++;
	temp = malloc(sizeof(char *) * (i + 1));
	while (i > k)
	{
		temp[k] = ft_strdup(tab[k]);
		k++;
	}
	temp[k] = 0;
	return (temp);
}


static int	ft_path_find(char **map, int *err, int x, int y)
{
	if (x <= 0  || y <= 0 ||  map[x][y] == ' ' || map[x][y] == 10)
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
	int i;
	int flag;

	flag = 0;
	i = 0;
	while (set[i])
	{
		// printf("c = %c, set[i] = %c\n",c, set[i]);
		if (c == set[i])
			flag = 1;
		i++;
	}
	return (flag);
}

static void	ft_initial_position_player(char **map, int i, int j, t_program *prog)
{
	if (map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'E' || map[i][j] == 'W')
	{
		printf("ok\n");
		prog->player.pos_x = i;
		prog->player.pos_y = j;
		if (map[i][j] == 'N')
		{
			prog->player.dir_x = -1;
			prog->player.dir_y = 0;
			prog->player.plane_x = 0;
			prog->player.plane_y = 0.66;
		}
		else if (map[i][j] == 'W')
		{
			prog->player.dir_x = 0;
			prog->player.dir_y = -1;
			prog->player.plane_x = -0.66;
			prog->player.plane_y = 0;
		}
		else if (map[i][j] == 'S')
		{
			prog->player.dir_x = 1;
			prog->player.dir_y = 0;
			prog->player.plane_x = 0;
			prog->player.plane_y = -0.66;
		}
		else if (map[i][j] == 'E')
		{
			prog->player.dir_x = 0;
			prog->player.dir_y = 1;
			prog->player.plane_x = 0.66;
			prog->player.plane_y = 0;
		}
		map[i][j] = '0';
	}
}

int	ft_validate_map(char **map, t_program *prog)
{
	int 	i;
	int		j;
	char	*set;
	char	**new_map;
	int		err;

	set = "01NSEW \n";
	i = 0;
	err = 0;
	while(map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_initial_position_player(map, i, j, prog);
			if (!ft_charcmp(map[i][j], set))
				return (0);
			j++;
		}
		i++;
	}
	new_map = ft_mapdup(map);
	ft_path_find(new_map, &err, prog->player.pos_x, prog->player.pos_y);
	// ft_free(new_map);
	if (err)
		return (0);
	return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:07:21 by javellis          #+#    #+#             */
/*   Updated: 2023/05/05 11:34:04 by javellis         ###   ########.fr       */
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
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				prog->player.pos_x = i;
				prog->player.pos_y = j;
			}
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
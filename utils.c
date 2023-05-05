/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:06:47 by javellis          #+#    #+#             */
/*   Updated: 2023/05/05 11:33:10 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_arr_cmp(char *str, char **set)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if(ft_strnstr(str, set[i], ft_strlen(str)))
			return(i);
		i++;
	}
	return (-1);
}

char **ft_strjoin_map(char **map, char *str)
{
	int		i;
	int		j;
	char	**new_map;

	if (!str || str[0] == '\n' || str[0] == 10)
		return (map);
	i = 0;
	j = 0;
	while(map[i])
		i++;
	new_map = malloc(sizeof(char *) * (i + 2));
	while (j < i)
	{
		new_map[j] = map[j];
		j++;
	}
	new_map[j] = ft_strdup(str);
	new_map[++j] = 0;
	//ft_free(map);
	return (new_map);
}

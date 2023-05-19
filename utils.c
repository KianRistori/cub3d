/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:06:47 by javellis          #+#    #+#             */
/*   Updated: 2023/05/19 10:53:55 by kristori         ###   ########.fr       */
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

int ft_add_shade(int color, float factor)
{
	int r = (color >> 16) & 0xFF;
	int g = (color >> 8) & 0xFF;
	int b = color & 0xFF;

	r *= factor;
	g *= factor;
	b *= factor;

	return ((r << 16) | (g << 8) | b);
}

int	ft_create_trgb(int t, t_color color)
{
	return (t << 24 | color.r << 16 | color.g << 8 | color.b);
}

void	ft_mlx_pixel_put(int x, int y, int color, t_image buffer)
{
	char	*i;
	int		y1;
	y1 = y * buffer.line_size;
	i = buffer.pixels + (y1 + x * (buffer.bits_per_pixel / 8));
	*(unsigned int *)i = color;
}

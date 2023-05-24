/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:25:07 by javellis          #+#    #+#             */
/*   Updated: 2023/05/23 16:22:31 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_texture_pixel(t_image texture, int x, int y)
{
	char	*pixel_addr;
	int		color;

	if (x < 0 || x >= texture.width || y < 0 || y >= texture.height)
		return (0);
	pixel_addr = texture.pixels
		+ (y * texture.line_size + x * (texture.bits_per_pixel / 8));
	color = *(unsigned int *)pixel_addr;
	return (color);
}

char	**ft_mapdup(char **tab)
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

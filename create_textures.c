/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:30:15 by javellis          #+#    #+#             */
/*   Updated: 2023/05/23 14:47:56 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	ft_get_image(t_program *prog, char *path)
{
	t_image img;
	if (path)
	{
		img.reference = mlx_xpm_file_to_image(prog->mlx, path, &img.width, &img.height);
		if (img.reference)
			img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	}
	return img;
}

void	ft_load_textures(t_program *prog)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		prog->textures[i] = ft_get_image(prog, prog->path[i]);
		printf("ref = %p", prog->textures[i].reference);
		i++;
	}		
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:40:25 by kristori          #+#    #+#             */
/*   Updated: 2023/05/24 12:14:28 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_img(t_program *prog, t_image *img, int size)
{
	int	i;

	i = 0;
	while (i < size)
		mlx_destroy_image(prog->mlx, img[i++].reference);
	free(img);
}

void	ft_free_all(t_program *program)
{
	ft_free_img(program, program->textures, 4);
	ft_free_img(program, program->wall_sprite, 9);
	mlx_destroy_image(program->mlx, program->buffer.reference);
	mlx_destroy_image(program->mlx, program->door.reference);
	mlx_destroy_window(program->mlx, program->window.reference);
	mlx_destroy_display(program->mlx);
	ft_free(program->map);
	ft_free(program->path);
	free(program->mlx);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

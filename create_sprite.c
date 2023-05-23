/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:42:46 by kristori          #+#    #+#             */
/*   Updated: 2023/05/23 10:45:08 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_wall_sprite(t_program *prog)
{
	prog->wall_sprite = (t_image *)malloc(sizeof(t_image) * 9);
	prog->wall_sprite[0] = ft_get_image(prog, "sprite/sprite_0.xpm");
	prog->wall_sprite[1] = ft_get_image(prog, "sprite/sprite_1.xpm");
	prog->wall_sprite[2] = ft_get_image(prog, "sprite/sprite_2.xpm");
	prog->wall_sprite[3] = ft_get_image(prog, "sprite/sprite_3.xpm");
	prog->wall_sprite[4] = ft_get_image(prog, "sprite/sprite_4.xpm");
	prog->wall_sprite[5] = ft_get_image(prog, "sprite/sprite_5.xpm");
	prog->wall_sprite[6] = ft_get_image(prog, "sprite/sprite_6.xpm");
	prog->wall_sprite[7] = ft_get_image(prog, "sprite/sprite_7.xpm");
	prog->wall_sprite[8] = ft_get_image(prog, "sprite/sprite_8.xpm");
}

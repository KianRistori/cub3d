/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:11:43 by kristori          #+#    #+#             */
/*   Updated: 2023/05/05 12:16:04 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_program program;
	int i = 0;

	if (ac == 2)
	{
		ft_map_parsing(av[1], &program);
		printf("path = %s", program.textures[0]->path);
		printf("path = %s", program.textures[1]->path);
		printf("path = %s", program.textures[2]->path);
		printf("path = %s", program.textures[3]->path);
		printf("floor[r] = %d\n", program.floor.r);
		printf("floor[g] = %d\n", program.floor.g);
		printf("floor[b] = %d\n", program.floor.b);
		printf("ceiling[r] = %d\n", program.ceiling.r);
		printf("ceiling[g] = %d\n", program.ceiling.g);
		printf("ceiling[b] = %d\n", program.ceiling.b);
		while (program.map[i])
		{
			printf("map[%d] = %s\n",i,program.map[i] );
			i++;
		}
		if (!ft_validate_map(program.map, &program))
		{
			printf("Error\nInvalid map!\n");
			return (0);
		}
	}
	program.mlx = mlx_init();
	program.window = ft_new_window(&program, "cub3d");
	program.player.dir_x = -1;
	program.player.dir_y = 0;
	program.player.plane_x = 0;
	program.player.plane_y = 0.66;
	program.time = 0;
	program.old_time = 0;
	mlx_hook(program.window.reference, 17, 0, *ft_close, &program);
	mlx_key_hook(program.window.reference, *ft_input, &program);
	// mlx_loop_hook(program.mlx, *ft_update, &program);
	mlx_loop(program.mlx);
	mlx_loop(program.mlx);
	return 0;
}
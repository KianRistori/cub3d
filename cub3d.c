/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:11:43 by kristori          #+#    #+#             */
/*   Updated: 2023/05/19 15:59:53 by javellis         ###   ########.fr       */
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
		printf("path = %s", program.path[0]);
		printf("path = %s", program.path[1]);
		printf("path = %s", program.path[2]);
		printf("path = %s", program.path[3]);
		printf("floor[r] = %d\n", program.floor.r);
		printf("floor[g] = %d\n", program.floor.g);
		printf("floor[b] = %d\n", program.floor.b);
		printf("ceiling[r] = %d\n", program.ceiling.r);
		printf("ceiling[g] = %d\n", program.ceiling.g);
		printf("ceiling[b] = %d\n", program.ceiling.b);
		while (program.map[i])
		{
			printf("map[%d] = %s",i, program.map[i]);
			i++;
		}
		printf("\n");
		if (!ft_validate_map(program.map, &program))
		{
			printf("Error\nInvalid map!\n");
			return (0);
		}
		program.mlx = mlx_init();
		program.window = ft_new_window(&program, "cub3d");
		program.buffer = ft_new_image(program.mlx, SCREEN_W, SCREEN_H);
		program.buffer2 = ft_new_image(program.mlx, SCREEN_W, SCREEN_H);
		ft_load_textures(&program);
		program.move_speed = 0.1;
		program.mouse_pos.x = 0;
		program.mouse_pos.y = 0;
		program.mouse_move = 0;
		// mlx_mouse_hide(program.mlx, program.window.reference);
		mlx_clear_window(program.mlx, program.window.reference);
		ft_create_image(&program, program.buffer);
		mlx_put_image_to_window(program.mlx, program.window.reference, program.buffer.reference, 0, 0);
		mlx_hook(program.window.reference, 17, 0, ft_close, &program);
		mlx_hook(program.window.reference, 2, (1L << 0), ft_input, &program);
		mlx_hook(program.window.reference, 6, (1L << 6), ft_mouse, &program);

		// mlx_key_hook(program.window.reference, ft_input, &program);
		// mlx_loop_hook(program.mlx, *ft_update, &program);
		mlx_loop(program.mlx);
	}
	else
		printf("Error, map request\n");
	return (0);
}

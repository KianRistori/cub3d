/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:11:43 by kristori          #+#    #+#             */
/*   Updated: 2023/05/24 12:51:09 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_program_var_init(t_program *program)
{
	program->frame = 0;
	program->frame_wall = 0;
	program->door = ft_get_image(program, "textures/Door.xpm");
	program->move_speed = 0.1;
	program->mouse_pos.x = 0;
	program->mouse_pos.y = 0;
	program->mouse_move = 0;
	mlx_clear_window(program->mlx, program->window.reference);
	ft_create_image(program, program->buffer);
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->buffer.reference, 0, 0);
}

static void	ft_free_error(t_program *prog)
{
	ft_free(prog->map);
	ft_free(prog->path);
	mlx_destroy_image(prog->mlx, prog->buffer.reference);
	free(prog->textures);
	mlx_destroy_window(prog->mlx, prog->window.reference);
	mlx_destroy_display(prog->mlx);
	free(prog->mlx);
	printf("Error\nInvalid texture path!\n");
}

static void	ft_hooks(t_program *prog)
{
	mlx_hook(prog->window.reference, 17, 0, ft_close, prog);
	mlx_hook(prog->window.reference, 2, (1L << 0), ft_input, prog);
	mlx_hook(prog->window.reference, 6, (1L << 6), ft_mouse, prog);
	mlx_loop_hook(prog->mlx, *ft_update, prog);
	mlx_loop(prog->mlx);
}

int	main(int ac, char **av)
{
	t_program	program;

	if (ac == 2)
	{
		if (open(av[1], O_RDWR) == -1 || !ft_map_parsing(av[1], &program)
			|| !ft_validate_map(program.map, &program))
		{
			printf("Error\nInvalid map!\n");
			return (0);
		}
		program.mlx = mlx_init();
		program.window = ft_new_window(&program, "cub3d");
		program.buffer = ft_new_image(program.mlx, SCREEN_W, SCREEN_H);
		if (!ft_load_textures(&program))
		{
			ft_free_error(&program);
			return (0);
		}
		ft_init_wall_sprite(&program);
		ft_program_var_init(&program);
		ft_hooks(&program);
	}
	else
		printf("Error, map request\n");
	return (0);
}

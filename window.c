/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:38:54 by kristori          #+#    #+#             */
/*   Updated: 2023/05/05 11:40:49 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(void *param)
{
	t_program	*program;

	program = (t_program *)param;
	ft_free_all(program);
	exit(0);
}

void	ft_exit(t_program *program, int key)
{
	if (key == 65307)
		ft_close(program);
}

t_window	ft_new_window(t_program *program, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(program->mlx, SCREEN_W, SCREEN_H, name);
	window.size.x = SCREEN_W;
	window.size.y = SCREEN_H;
	return (window);
}

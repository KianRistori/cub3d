/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:11:43 by kristori          #+#    #+#             */
/*   Updated: 2023/05/03 11:28:00 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{
	t_program program;

	program.mlx = mlx_init();
	program.window.reference = mlx_new_window(program.mlx, SCREEN_W, SCREEN_H, "cub3d");
	mlx_loop(program.mlx);
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:40:25 by kristori          #+#    #+#             */
/*   Updated: 2023/05/05 11:41:11 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_all(t_program *program)
{
	mlx_destroy_window(program->mlx, program->window.reference);
	mlx_destroy_display(program->mlx);
	free(program->mlx);
}

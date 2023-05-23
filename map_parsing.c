/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:38:26 by javellis          #+#    #+#             */
/*   Updated: 2023/05/23 14:43:11 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_get_textures(char *line, t_program *prog)
{
	char	**char_set;
	int		index;
	char	**split;

	char_set = malloc(sizeof(char *) * 5);
	char_set[0] = ft_strdup("NO");
	char_set[1] = ft_strdup("SO");
	char_set[2] = ft_strdup("WE");
	char_set[3] = ft_strdup("EA");
	char_set[4] = 0;
	if (line)
	{
		index = ft_arr_cmp(line, char_set);
		if (index != -1 && prog->path[index] == NULL)
		{
			split = ft_split(line, ' ');
			prog->path[index] = ft_strtrim(split[1], "\n");
			ft_free(char_set);
			ft_free(split);
			return (1);
		}
	}
	ft_free(char_set);
	return (0);
}

static int	ft_get_color(char *line, t_program **prog)
{
	int		count;
	char	**split;

	count = 0;
	if (line)
	{
		if (line[0] == 'F')
		{
			split = ft_split(line, ',');
			(*prog)->floor.r = ft_atoi(split[0]);
			(*prog)->floor.g = ft_atoi(split[1]);
			(*prog)->floor.b = ft_atoi(split[2]);
			count++;
			ft_free(split);
		}
		else if (line[0] == 'C')
		{
			split = ft_split(line, ',');
			(*prog)->ceiling.r = ft_atoi(split[0]);
			(*prog)->ceiling.g = ft_atoi(split[1]);
			(*prog)->ceiling.b = ft_atoi(split[2]);
			count++;
			ft_free(split);
		}
	}
	return (count);
}

static void	ft_prog_init(t_program *prog)
{
	prog->path = malloc(sizeof(char *) * 5);
	prog->textures = malloc(sizeof(t_image) * 4);
	prog->path[0] = NULL;
	prog->path[1] = NULL;
	prog->path[2] = NULL;
	prog->path[3] = NULL;
	prog->path[4] = 0;
	prog->map = malloc(sizeof(char *) * 1);
	prog->map[0] = 0;
}

int	ft_map_parsing(char *map, t_program *prog)
{
	int		path;
	char	*line;
	int		count;

	count = 0;
	ft_prog_init(prog);
    path = open(map, O_RDWR);
    line = get_next_line(path);
	while (line != NULL && count < 6)
	{
		count += ft_get_textures(line, prog);
		count += ft_get_color(line, &prog);
		free(line);
		line = get_next_line(path);
	}
	while (line != NULL)
	{
		prog->map = ft_strjoin_map(prog->map, line);
		free(line);
		line = get_next_line(path);
	}
	if (count == 6)
		return (1);
	else
		return (0);
}
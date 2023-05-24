/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:38:26 by javellis          #+#    #+#             */
/*   Updated: 2023/05/24 12:19:04 by javellis         ###   ########.fr       */
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

static void	ft_set_rgb(char *line, t_color *color)
{
	char	**split;

	split = ft_split(line, ',');
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	ft_free(split);
}

static int	ft_get_color(char *line, t_program **prog)
{
	int		count;

	count = 0;
	if (line)
	{
		if (line[0] == 'F')
		{
			ft_set_rgb(line, &((*prog)->floor));
			count++;
		}
		else if (line[0] == 'C')
		{
			ft_set_rgb(line, &((*prog)->ceiling));
			count++;
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
	if (count == 6 || !path)
		return (1);
	return (0);
}

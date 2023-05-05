/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:38:26 by javellis          #+#    #+#             */
/*   Updated: 2023/05/05 11:34:03 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_get_textures(char *line, t_image **textures)
{
	char	*char_set[4];
	int		index;
	char	**split;

	char_set[0] = ft_strdup("NO");
	char_set[1] = ft_strdup("SO");
	char_set[2] = ft_strdup("WE");
	char_set[3] = ft_strdup("EA");
	if (line)
	{
		index = ft_arr_cmp(line, char_set);
		if (index != -1 && textures[index]->path == NULL)
		{
			split = ft_split(line, ' ');
			textures[index]->path = split[1];
			return (1);
			//ft_free()
		}
	}
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
			// printf("split[0] = %s\n",split[0]);
			// printf("split[1] = %s\n",split[1]);
			// printf("split[2] = %s\n",split[2]);
			(*prog)->floor.r = ft_atoi(split[0]);
			(*prog)->floor.g = ft_atoi(split[1]);
			(*prog)->floor.b = ft_atoi(split[2]);
			count++;
			//ft_free()
		}
		else if (line[0] == 'C')
		{
			split = ft_split(line, ',');
			// printf("split[0] = %s\n",split[0]);
			// printf("split[1] = %s\n",split[1]);
			// printf("split[2] = %s\n",split[2]);
			(*prog)->ceiling.r = ft_atoi(split[0]);
			(*prog)->ceiling.g = ft_atoi(split[1]);
			(*prog)->ceiling.b = ft_atoi(split[2]);
			count++;
			//ft_free()
		}
	}
	return (count);
}

static t_image	**ft_texture_init()
{
	t_image	**textures;

	textures = malloc(sizeof(t_image *) * 4);
	textures[0] = malloc(sizeof(t_image));
	textures[1] = malloc(sizeof(t_image));
	textures[2] = malloc(sizeof(t_image));
	textures[3] = malloc(sizeof(t_image));
	textures[0]->path = NULL;
	textures[1]->path = NULL;
	textures[2]->path = NULL;
	textures[3]->path = NULL;
	return (textures);
}

int	ft_map_parsing(char *map, t_program *prog)
{
	int		path;
	char	*line;
	t_image	**textures;
	int		count;

	count = 0;
	prog->map = malloc(sizeof(char *) * 2);
	prog->map[0] = 0;
	textures = NULL;
	textures = ft_texture_init();
    path = open(map, O_RDWR);
    line = get_next_line(path);
	while (line != NULL && count < 6)
	{
		count += ft_get_textures(line, textures);
		count += ft_get_color(line, &prog);
		// free(line);
		line = get_next_line(path);
	}
	prog->textures = textures;
	while (line != NULL)
	{
		prog->map = ft_strjoin_map(prog->map, line);
		// free(line);
		line = get_next_line(path);
	}
	if (count == 6)
		return (1);
	else
		return (0);
}
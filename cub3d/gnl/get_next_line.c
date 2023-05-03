/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:13:35 by kristori          #+#    #+#             */
/*   Updated: 2022/11/14 16:28:07 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *save)
{
	char	*ris;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	ris = (char *)malloc(sizeof(char) * (ft_strlen(save) + 1));
	if (!ris)
		return (NULL);
	while (save[i] && save[i] != '\n')
	{
		ris[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		ris[i] = save[i];
		i++;
	}
	ris[i] = '\0';
	return (ris);
}

char	*ft_save(char *save)
{
	char	*ris;
	int		i;
	int		j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	ris = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!ris)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		ris[j++] = save[i++];
	ris[j] = '\0';
	free(save);
	return (ris);
}

char	*ft_read_and_save(int fd, char *save)
{
	char	*buf;
	int		read_bytes;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char		*save;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}

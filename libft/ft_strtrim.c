/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:38:43 by javellis          #+#    #+#             */
/*   Updated: 2023/05/15 12:45:31 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strtrim(char *s1, char *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = 0;
	if (set != 0 && s1 != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		while (ft_strchr(set, s1[i]) && s1[i])
			i++;
		while (ft_strchr(set, s1[j - 1]) && j > i && s1[j - 1])
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + 1));
		if (str)
			ft_strlcpy(str, (char *)&s1[i], j - i + 1);
		int i= 0;
		while (str[i])
		{
			printf("str = %c\n", str[i++]);
		}
		
	}
	return (str);
}

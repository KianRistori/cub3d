/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:33:35 by kristori          #+#    #+#             */
/*   Updated: 2022/11/15 13:12:25 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*ris;
	int		i;

	i = 0;
	ris = (char *)malloc(ft_strlen(s) * (sizeof(char) + 1));
	if (!ris)
		return (ris);
	while (s[i])
	{
		ris[i] = s[i];
		i++;
	}
	ris[i] = '\0';
	return (ris);
}

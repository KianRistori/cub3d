/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:55:32 by javellis          #+#    #+#             */
/*   Updated: 2022/10/05 10:55:37 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	i = 0;
	j = 0;
	ptr = (char *)big;
	if (little == NULL || little[0] == '\0')
		return ((char *)big);
	while (len > i && big[i] != '\0')
	{
		while (big[i + j] == little[j] && big[i + j] != '\0' && len > i + j)
			j++;
		if (little[j] == '\0')
			return (ptr + i);
		j = 0;
		i++;
	}
	return (NULL);
}

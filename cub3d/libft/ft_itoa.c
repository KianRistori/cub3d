/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:21:31 by kristori          #+#    #+#             */
/*   Updated: 2022/11/14 15:12:33 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static int	ft_intlen(int nbr)
{
	int	i;

	i = 0;
	if (nbr <= 0)
		i++;
	while (nbr != 0)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*ris;
	int		len;

	len = ft_intlen(nbr);
	ris = (char *)malloc(sizeof(char) * len + 1);
	if (!ris)
		return (NULL);
	if (nbr == 0)
		ris[0] = '0';
	ris[len] = '\0';
	while (nbr != 0)
	{
		ris[len - 1] = ft_absolute_value(nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (ris);
}

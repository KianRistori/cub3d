/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:35:09 by kristori          #+#    #+#             */
/*   Updated: 2023/05/24 11:54:10 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"

char	*ft_itoa(int n);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strdup(char *s);
char	*ft_strnstr(const char *big, const char *little, unsigned int len);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_strtrim(char *s1, char *set);
size_t	ft_strlcpy(char *dest, char *src, size_t size);

#endif

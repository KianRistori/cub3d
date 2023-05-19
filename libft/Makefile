# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javellis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 12:54:12 by kristori          #+#    #+#              #
#    Updated: 2023/05/19 16:02:33 by javellis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC	= ft_itoa.c ft_strcpy.c ft_strcat.c ft_strdup.c ft_strnstr.c ft_split.c ft_atoi.c ft_strtrim.c ft_strlcpy.c

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME) : $(SRC)
	@gcc -Wall -Werror -Wextra -c $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

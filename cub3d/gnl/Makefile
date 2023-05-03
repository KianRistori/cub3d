# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kristori <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 11:03:01 by kristori          #+#    #+#              #
#    Updated: 2022/11/04 11:03:31 by kristori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= gnl.a

SRC	= get_next_line.c  get_next_line_utils.c

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME) : $(SRC)
	@gcc -Wall -Werror -Wextra -c $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME)

bonus:
	@gcc -Wall -Werror -Wextra -c $(BONUS)
	@ar rc $(NAME) $(BONUS) $(OBJ_BONUS)

re: fclean all

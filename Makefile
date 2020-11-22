# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 13:05:45 by idelgado          #+#    #+#              #
#    Updated: 2020/10/07 18:27:44 by idelgado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PRINTF = 	ft_printf.c \
				flaghandler.c
CFLAGS = -Wall -Wextra -Werror

all:
	make -C ./libft
	gcc -c $(CFLAGS) $(SRC_PRINTF) libft/libft.a
	ar rc libftprintf.a *.o
	ranlib libftprintf.a
	rm -f *.o
clean:
	rm -f *.o

fclean: clean
	rm -f *.a
re: fclean all

.PHONY: all clean fclean re bonus

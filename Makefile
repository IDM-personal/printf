# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idm <idm@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 13:05:45 by idelgado          #+#    #+#              #
#    Updated: 2020/11/30 11:01:36 by idm              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PF =    flaghandler.c \
			ft_itoa_hex.c

PRINTF =    ft_printf.c

OBJET_PRINTF = $(PRINTF:.c=.o)

OBJET_LIB =  libft/*.o

LIBFT_PATH = ./libft

PUTAFLAGS = -Wall -Werror -Wextra

GCC = gcc

AR = ar

ARFLAGS = rc

MAKE = make

.PHONY: clean fclean all re test g

all: $(NAME)

$(NAME):
		@$(MAKE) -C $(LIBFT_PATH)
		@echo Compiling $(NAME)
		@$(GCC) $(FLAGS) -c $(SRC_PF) $(PRINTF)
		@$(AR) $(ARFLAGS) $(NAME) *.o */*.o
		@ranlib $(NAME)
		@echo ======[Done]======

%.o : %.c
		@echo "$(NAME) >>> Add/Update $^"
clean:
		@$(MAKE) -C $(LIBFT_PATH) fclean
		@echo Clean objects $(NAME)
		@rm -rf $(OBJET_PF) $(OBJET_PRINTF)

fclean: clean
		@$(MAKE) -C $(LIBFT_PATH) fclean
		@echo Clean $(NAME)
		@rm -rf $(NAME)
		@echo ======[Clean]======

g:
	git pull

test: g re
	gcc main.c libftprintf.a && ./a.out
re: fclean all
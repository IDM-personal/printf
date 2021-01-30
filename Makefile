# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 13:05:45 by idelgado          #+#    #+#              #
#    Updated: 2021/01/30 20:15:41 by idelgado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PF =    flaghandler.c\
			length_formal.c\
			ft_findprecs.c\
			ft_itoa_hex.c\
			ft_itoa_hex_u.c\
			ft_resolve_hex.c\
			ft_resolve_pointer.c\
			ft_resolve_string.c\
			ft_resolve_char.c\
			ft_resolve_pct.c\
			ft_resolve_i.c\
			ft_resolve_u.c\
			ft_resolve_i_neg.c

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
		@rm -rf *.o

fclean: clean
		@$(MAKE) -C $(LIBFT_PATH) fclean
		@echo Clean $(NAME)
		@rm -rf $(NAME)
		@rm -rf *.o *.a
		@echo ======[Clean]======

g:
	git pull

test: g re
	gcc main.c libftprintf.a && ./a.out
re: fclean all

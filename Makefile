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

NAME = libft/
SRC_OP1 = 	libft/ft_atoi.c  	 		\
			libft/ft_bzero.c 	 		\
			libft/ft_calloc.c  		\
			libft/ft_isalnum.c 		\
			libft/ft_isalpha.c 		\
			libft/ft_isascii.c 		\
			libft/ft_isdigit.c 		\
			libft/ft_isprint.c 		\
			libft/ft_memccpy.c 		\
			libft/ft_memchr.c  		\
			libft/ft_memcmp.c  		\
			libft/ft_memcpy.c  		\
			libft/ft_memmove.c 		\
			libft/ft_memset.c  		\
			libft/ft_strchr.c  		\
			libft/ft_strdup.c  		\
			libft/ft_strlcat.c 		\
			libft/ft_strlcpy.c 		\
			libft/ft_strlen.c  		\
			libft/ft_strncmp.c 		\
			libft/ft_strnstr.c 		\
			libft/ft_strrchr.c 		\
			libft/ft_strpchr.c 		\
			libft/ft_tolower.c 		\
			libft/ft_toupper.c
SRC_OP2 = 	libft/ft_substr.c  		\
			libft/ft_strjoin.c 		\
			libft/ft_strtrim.c 		\
			libft/ft_putchar_fd.c 	\
			libft/ft_putstr_fd.c 		\
			libft/ft_putnbr_fd.c		\
			libft/ft_itoa.c			\
			libft/ft_strmapi.c		\
			libft/ft_split.c			\
			libft/ft_putendl_fd.c
CFLAGS = -Wall -Wextra -Werror

all:
	gcc -c $(CFLAGS) ft_printf.c $(SRC_OP1) $(SRC_OP2)
	ar rc libftprintf.a *.o
	ranlib libftprintf.a
clean:
	rm -f *.o

fclean: clean
	rm -f *.a
bonus:
	gcc -c $(CFLAGS) $(SRC_OP1) $(SRC_OP2) $(BONUS)
	ar rc $(LIBNAME) *.o
	ranlib $(LIBNAME)
re: fclean all

.PHONY: all clean fclean re bonus

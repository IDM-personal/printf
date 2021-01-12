# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idm <idm@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 13:05:45 by idelgado          #+#    #+#              #
#    Updated: 2021/01/12 02:35:29 by idm              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
SRC_OP1 = 	ft_atoi.c  	 		\
			ft_bzero.c 	 		\
			ft_calloc.c  		\
			ft_isalnum.c 		\
			ft_isalpha.c 		\
			ft_isascii.c 		\
			ft_isdigit.c 		\
			ft_isprint.c 		\
			ft_memccpy.c 		\
			ft_memchr.c  		\
			ft_memcmp.c  		\
			ft_memcpy.c  		\
			ft_memmove.c 		\
			ft_memset.c  		\
			ft_strchr.c  		\
			ft_strdup.c  		\
			ft_strlcat.c 		\
			ft_strlcpy.c 		\
			ft_strlen.c  		\
			ft_strncmp.c 		\
			ft_strnstr.c 		\
			ft_strrchr.c 		\
			ft_tolower.c 		\
			ft_toupper.c		
SRC_OP2 = 	ft_substr.c  		\
			ft_strjoin.c 		\
			ft_strtrim.c 		\
			ft_putchar_fd.c 	\
			ft_putstr_fd.c 		\
			ft_putnbr_fd.c		\
			ft_itoa.c			\
			ft_strmapi.c		\
			ft_split.c			\
			ft_putendl_fd.c		\
			ft_strpchr.c
SRC_EXTRA = ft_putstr_n.c		\
			ft_putblanks.c		\
			ft_putzeros.c
CFLAGS = -Wall -Wextra -Werror
LIBNAME = libft.a

all: $(NAME)

$(NAME):
	gcc -c $(CFLAGS) $(SRC_OP1) $(SRC_OP2) $(SRC_EXTRA)
	ar rc $(LIBNAME) *.o
	ranlib $(LIBNAME)
clean:
	rm -f *.o

fclean: clean
	rm -f *.a
re: fclean all

.PHONY: all clean fclean re bonus

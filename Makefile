# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkarima <kkarima@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/16 18:22:22 by kkarima           #+#    #+#              #
#    Updated: 2026/11/16 23:03:53 by kkarima          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c ft_putchar_str.c ft_putnbrs.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

all : $(NAME)

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f libftprintf.a

re : fclean all

.PHONY : all clean fclean re

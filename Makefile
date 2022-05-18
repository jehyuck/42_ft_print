# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeyou <jeyou@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 20:28:53 by jeyou             #+#    #+#              #
#    Updated: 2022/05/18 17:51:16 by jeyou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRCS = ft_printf_utils.c ft_printf.c ft_strchr.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_putbase.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
ARS = ar crs

all : $(NAME)

$(NAME) : $(OBJS)
	$(ARS) $@ $^ 

%.o : %.c %.h 
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all


.PHONY : all clean fclean re

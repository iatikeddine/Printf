# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/31 10:18:20 by iatikedd          #+#    #+#              #
#    Updated: 2025/11/07 07:59:03 by iatikedd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC       = ft_pointer.c ft_printf.c ft_putnbr_lower_base.c ft_putnbr_upper_base.c \
            ft_putnbr_unsigned.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
	    ft_strlen.c
OBJS      = $(SRC:.c=.o)
NAME      = libftprintf.a
CC        = cc
CFLAGS    = -Wall -Wextra -Werror
AR        = ar rcs
RM        = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

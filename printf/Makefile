# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 17:38:27 by ldiogo            #+#    #+#              #
#    Updated: 2022/05/02 15:00:17 by ldiogo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIB1	= ar -rcs
LIB2	= ranlib
RM		= /bin/rm -f

NAME	= libftprintf.a

INCLUDE	= ft_printf.h
SRCS	= printf.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putnbr_fd.c libft/ft_putnbrn_fd.c libft/ft_strlen.c libft/ft_declen.c libft/ft_intlen.c libft/ft_undeclen.c libft/ft_hex.c libft/ft_strrev.c libft/ft_hexp.c
OBJS	= $(SRCS:.c=.o)

all:		$(NAME) clean

$(NAME):	$(OBJS) $(INCLUDE)
			$(LIB1) $(NAME) $(OBJS)
			$(LIB2) $(NAME)

.c.o:
			$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

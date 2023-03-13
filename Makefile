# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 04:51:18 by tcasale           #+#    #+#              #
#    Updated: 2023/03/11 01:47:35 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

SRCS	= $(wildcard srcs/*.c) \
			$(wildcard srcs/lexer/*.c) \
			$(wildcard srcs/parser/*.c) \
			$(wildcard srcs/executor/*.c)

OBJS	=${SRCS:.c=.o}

HEADER	= includes

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

%.o: %.c
			$(CC) $(CFLAGS) -I./srcs/libftprintf/libftprintf.a  -c  $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS) ./srcs/libftprintf/libftprintf.a
			$(CC) $(OBJS) -lreadline ./srcs/libftprintf/libftprintf.a -o $(NAME)

bonus:	$(NAME)

./srcs/libftprintf/libftprintf.a:
	$(MAKE) -C ./srcs/libftprintf

clean:
		$(MAKE) -C ./srcs/libftprintf $@
		$(RM) $(OBJS)

fclean:	clean
		$(MAKE) -C ./srcs/libftprintf $@
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

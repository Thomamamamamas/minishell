# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 14:36:21 by tcasale           #+#    #+#              #
#    Updated: 2023/02/19 14:22:55 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= libft.a

SRCS	= $(wildcard *.c)

OBJS	= ${SRCS:.c=.o}

OBJS	= ${SRCS:.c=.o}

HEADER	= includes

CC		= gcc
RM		= rm -f
AR		= ar rcs

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
			${CC} -c ${CFLAGS} -o $@ $<

all: $(NAME)

$(NAME):	$(OBJS) $(OBJS_SUPP)
			$(AR) $@ $^

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re

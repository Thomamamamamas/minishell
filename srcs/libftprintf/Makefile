# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 14:52:20 by tcasale           #+#    #+#              #
#    Updated: 2023/02/19 14:20:18 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= libftprintf.a

OBJS		= ${SRCS:.c=.o}

HEADER	= includes

CC		= gcc
RM		= rm -f
AR		= ar rcs

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
			${CC} -c ${CFLAGS} -I./Libft/libft.a -o $@ $<

all: $(NAME)


$(NAME):	./ft_printf/libftprintf.a ./get_next_line/get_next_line.a

./ft_printf/libftprintf.a:
	$(MAKE) -C ./ft_printf
	cp ./ft_printf/libftprintf.a ./

./get_next_line/get_next_line.a:
	$(MAKE) -C ./get_next_line

bonus: $(NAME)

clean:
		$(MAKE) -C ./ft_printf $@
		$(MAKE) -C ./get_next_line $@
		${RM} ${OBJS}

fclean:	clean
		$(MAKE) -C ./ft_printf $@
		$(MAKE) -C ./get_next_line $@
		${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re libft

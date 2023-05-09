# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 14:52:20 by tcasale           #+#    #+#              #
#    Updated: 2023/02/19 13:21:23 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= libftprintf.a

SRCS	=	ft_printf.c \
			ft_printf_utils.c \
			ft_printf_utils2.c \
			ft_printf_parsing.c \
			ft_printf_conversion.c \
			ft_printf_precision.c

OBJS		= ${SRCS:.c=.o}

HEADER	= includes

CC		= gcc
RM		= rm -f
AR		= ar rcs

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
			${CC} -c ${CFLAGS} -I../Libft/libft.a -o $@ $<

all: $(NAME)


$(NAME):	../libft/libft.a ${OBJS}
			$(AR) ${NAME} $(OBJS)

../libft/libft.a:
	$(MAKE) -C ../libft
	cp ../libft/libft.a $(NAME)

bonus: $(NAME)

clean:
		$(MAKE) -C ../libft $@
		${RM} ${OBJS}

fclean:	clean
		$(MAKE) -C ../libft $@
		${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re libft

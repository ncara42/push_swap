# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/18 08:08:58 by ncaravac          #+#    #+#              #
#    Updated: 2026/01/07 17:32:19 by ncaravac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
HD = ./includes
CFLAGS = -Wall -Werror -Wextra -fPIC
INCLUDES = -I./includes

SRC = srcs/ft_printf.c\
	srcs/ft_putchar.c\
	srcs/ft_puthex.c\
	srcs/ft_putnbr.c\
	srcs/ft_float.c\
	srcs/ft_putptr.c\
	srcs/ft_putstr.c\
	srcs/ft_putunsigned.c

OBJS_DIR = objs
OBJ = ${SRC:srcs/%.c=${OBJS_DIR}/%.o}

all: ${NAME}

${NAME}: ${OBJ}
	@ar rcs ${NAME} ${OBJ}
	@echo "FT_PRINTF COMPILED!"

${OBJS_DIR}/%.o: srcs/%.c Makefile includes/ft_printf.h
	@mkdir -p ${OBJS_DIR}
	@${CC} ${CFLAGS} -c $< -o $@
	@echo "Compiling: $<"

clean:
	@rm -rf ${OBJS_DIR}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

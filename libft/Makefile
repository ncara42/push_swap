# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 11:54:06 by ncaravac          #+#    #+#              #
#    Updated: 2026/01/11 19:23:19 by ncaravac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -fPIC -ggdb3
INCLUDES = -I./includes

SRC =	srcs/ft_bzero.c\
		srcs/ft_strlen.c\
		srcs/ft_split.c\
		srcs/ft_strcmp.c\
		srcs/ft_lstnew.c\
		srcs/ft_putnbr.c\
		srcs/ft_putnbr_fd.c\
		srcs/ft_putchar_fd.c\
		srcs/ft_lstsize.c\
		srcs/ft_lstlast.c\
		srcs/ft_lstadd_back.c\
		srcs/ft_atol.c\
		srcs/ft_check_num.c\
		srcs/ft_bubblesort.c\
		srcs/ft_array_sort.c\
		srcs/ft_check_flags.c

OBJS_DIR = objs
OBJ = ${SRC:srcs/%.c=${OBJS_DIR}/%.o}

all: ${NAME}

${NAME}: ${OBJ}
	@ar rcs ${NAME} ${OBJ}
	@echo "LIBFT COMPILED!"

$(OBJS_DIR)/%.o: srcs/%.c Makefile includes/libft.h
	@mkdir -p $(OBJS_DIR)
	@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@
	@echo "Compiling: $<"

clean:
	@rm -rf ${OBJS_DIR}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

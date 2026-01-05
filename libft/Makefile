# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: admin <admin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 11:54:06 by ncaravac          #+#    #+#              #
#    Updated: 2026/01/05 23:26:39 by admin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -fPIC
INCLUDES = -I./includes

SRC =	srcs/ft_bzero.c\
		srcs/ft_strlen.c\
		srcs/ft_split.c\
		srcs/ft_strcmp.c\
		srcs/ft_lstnew.c\
		srcs/ft_putnbr.c\
		srcs/ft_lstsize.c\
		srcs/ft_lstlast.c\
		srcs/ft_lstadd_back.c\
		srcs/ft_atol.c\
		srcs/ft_check_num.c\

OBJS_DIR = objs
OBJ = ${SRC:srcs/%.c=${OBJS_DIR}/%.o}

all: ${NAME}

${NAME}: ${OBJ}
	@ar rcs ${NAME} ${OBJ}
	@echo "Libft compiled!"

$(OBJS_DIR)/%.o: srcs/%.c Makefile includes/libft.h
	@mkdir -p ${OBJS_DIR}
	@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@
	@echo "Compiling: $<"

clean:
	@rm -rf ${OBJS_DIR}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

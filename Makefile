# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: admin <admin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/30 14:22:24 by vvan-ach          #+#    #+#              #
#    Updated: 2026/01/05 23:34:41 by admin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
DNAME = dpush_swap
CC = cc
CFLAGS = -Wextra -Werror -Wall
INCLUDES = -I./includes -I$(LIBFT_DIR)/includes -I$(PRINTF_DIR)/includes

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

LDFLAGS = -I./includes -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

SRCS =	srcs/push_swap.c \
		srcs/swap.c \
		srcs/push.c \
		srcs/rotate.c \
		srcs/sqrt.c \
		srcs/simple.c \
		srcs/medium.c \
		srcs/complex.c \
		srcs/sort_three.c \
		srcs/free.c \
		srcs/bubblesort.c \
		srcs/sort_three_a_b.c \
		srcs/divideinchunks.c \
		srcs/parseoptions.c\
		srcs/chooseandusealgo.c\
		srcs/bench_medium.c\
		srcs/bench_simple.c\
		srcs/printbenchinfo.c\
		srcs/bench_complex.c\

OBJS_DIR = objs
OBJS = $(SRCS:srcs/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME):  $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

debug: $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) -g -O0 $(CFLAGS) $(SRCS) -o $(DNAME)

$(OBJS_DIR)/%.o: srcs/%.c Makefile includes/push_swap.h
	@mkdir -p ${OBJS_DIR}
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiling: $<"

clean:
	rm -rf $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re : fclean all

.PHONY: all clean fclean re debug

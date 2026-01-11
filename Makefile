# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: admin <admin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/30 14:22:24 by vvan-ach          #+#    #+#              #
#    Updated: 2026/01/11 04:49:20 by admin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
DNAME = dpush_swap
CC = cc
CFLAGS = -Wextra -Werror -Wall
INCLUDES = -I./includes -I$(LIBFT_DIR)/includes -I$(PRINTF_DIR)/includes

ifeq ($(DEBUG), 1)
	CFLAGS += -g -O0
	BUILD_MSG = "Compiling debug:"
else
	CFLAGS += -O2
	BUILD_MSG = "Compiling:"
endif

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

LDFLAGS = -I./includes -L$(LIBFT_DIR) -lft

SRCS =	srcs/push_swap.c \
		srcs/disorder_index.c \
		srcs/swap.c \
		srcs/push.c \
		srcs/rotate.c \
		srcs/reverse_rotate.c \
		srcs/simple.c \
		srcs/medium.c \
		srcs/complex.c \
		srcs/sort_three-v1.c \
		srcs/sort_three-v2.c \
		srcs/free.c \
		srcs/parse_options.c\
		srcs/count_bench.c \
		srcs/adaptive.c \
		srcs/bench_simple.c \
		srcs/bench_medium.c \
		srcs/bench_complex.c \
		srcs/bench_medium_aux.c \
		srcs/medium_aux.c \
		srcs/print_bench_info.c

OBJS_DIR = objs
OBJS = $(SRCS:srcs/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME):  $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "PUSH_SWAP COMPILED!"

$(LIBFT):
	@make -C $(LIBFT_DIR)

debug: $(LIBFT)
	make DEBUG=1 -B $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(DNAME)
	@echo "PUSH_SWAP DEBUG COMPILED!"

$(OBJS_DIR)/%.o: srcs/%.c Makefile includes/push_swap.h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(BUILD_MSG) $<"

clean:
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME) $(DNAME)
	@make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY: all clean fclean re

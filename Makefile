# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/30 14:22:24 by vvan-ach          #+#    #+#              #
#    Updated: 2026/01/08 01:56:53 by vvan-ach         ###   ########.fr        #
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

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

LDFLAGS = -I./includes -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

SRCS =	srcs/push_swap.c \
		srcs/swap.c \
		srcs/push.c \
		srcs/rotate.c \
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
		srcs/print_bench_info.c

OBJS_DIR = objs
OBJS = $(SRCS:srcs/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME):  $(LIBFT) $(PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "PUSH_SWAP COMPILED!"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

debug: $(LIBFT) $(PRINTF)
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
	@make -C $(PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME) $(DNAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re : fclean all

.PHONY: all clean fclean re

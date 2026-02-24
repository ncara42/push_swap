# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/30 14:22:24 by vvan-ach          #+#    #+#              #
#    Updated: 2026/01/12 19:35:29 by vvan-ach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
DNAME = dpush_swap
CC = cc
CFLAGS = -Wextra -Werror -Wall
INCLUDES = -I./includes -I$(LIBFT_DIR)/includes

ifeq ($(DEBUG), 1)
	CFLAGS += -ggdb3
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
		srcs/bench_simple.c \
		srcs/medium.c \
		srcs/bench_medium.c \
		srcs/bench_medium_aux.c \
		srcs/complex.c \
		srcs/bench_complex.c \
		srcs/bench_complex_aux.c \
		srcs/sort_three-v1.c \
		srcs/sort_three-v2.c \
		srcs/sort_moves.c \
		srcs/free.c \
		srcs/parse_options.c\
		srcs/count_bench.c \
		srcs/adaptive.c \
		srcs/medium_aux.c \
		srcs/print_bench_info.c

OBJS_DIR = objs
OBJS = $(SRCS:srcs/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME):  libft $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "PUSH_SWAP COMPILED!"

libft: 
	@make -C $(LIBFT_DIR)

debug: libft #$(LIBFT)
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

.PHONY: all clean fclean re libft debug

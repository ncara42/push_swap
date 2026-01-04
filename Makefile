# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/30 14:22:24 by vvan-ach          #+#    #+#              #
#    Updated: 2026/01/04 00:56:58 by vvan-ach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

DNAME = dpush_swap

CC = cc

CFLAGS = -Wextra -Werror -Wall

SRCS = push_swap.c swap.c push.c rotate_a.c rotate_b.c \
	   ft_strcmp.c ft_split.c ft_lstsize.c ft_lstnew.c \
	   ft_lstlast.c ft_lstadd_back.c ft_check_num.c ft_check_minmax.c \
	   ft_atol.c sqrt.c simple.c medium.c sort_three.c complex.c \
	   sort_three_complex.c freelist.c freechunks.c bubblesort.c \
	   divideinchunks.c ft_strlen.c parseoptions.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

debug: $(OBJS)
	$(CC) -g -O0 $(CFLAGS) $(SRCS) -o $(DNAME)

%.o: %.c push_swap.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(DNAME)

re : fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/30 14:22:24 by vvan-ach          #+#    #+#              #
#    Updated: 2026/01/05 20:07:42 by vvan-ach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

DNAME = dpush_swap

CC = cc

CFLAGS = -Wextra -Werror -Wall

SRCS = push_swap.c swap.c push.c rotate.c \
	   ft_strcmp.c ft_split.c ft_lstsize.c ft_lstnew.c \
	   ft_lstlast.c ft_lstadd_back.c ft_check_num.c \
	   ft_atol.c sqrt.c simple.c medium.c complex.c \
	   sort_three.c free.c bubblesort.c sort_three_a_b.c \
	   divideinchunks.c ft_strlen.c parseoptions.c chooseandusealgo.c \
	   bench_medium.c bench_simple.c printbenchinfo.c ft_putnbr.c \
	   ft_bzero.c bench_complex.c

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

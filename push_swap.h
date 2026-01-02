/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 22:08:10 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/02 18:04:49 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	long				content;
	struct s_list		*next;
}	t_list;

typedef struct s_chunks
{
	long	**chunks;
	size_t	*sizes;
	size_t	count;
}	t_chunks;

// Functions
int			check_num(char **argv);
int			check_minmax(char **argv);
int			ft_strcmp(char *s1, char *s2);
char		**ft_split(char const *s, char c);
t_list		*ft_lstnew(long value);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);
long		ft_atol(char *argv_char);
size_t		int_sqrt(size_t n);
void		sort_three(t_list **stack_a);
void		sort_three_b(t_list **stack_a, t_list **stack_b, int len);
void		free_list(t_list *stack_a);

// Simple
void		simple(t_list **stack_a, t_list **stack_b);

// Medium
void		medium(t_list **stack_a, t_list **stack_b);
long		*getsortedarr(t_list *stack, int len);
t_chunks	*divideinchunks(t_list *stack_a);
void		freechunks(t_chunks *chunks);
void		bubblesort(long	*arr, size_t size);

// Complex
void		complex(t_list **stack_a, t_list **stack_b, int len);
void		complex_b(t_list **stack_a, t_list **stack_b, int pushed);
void		sort_three_complex(t_list **stack_a, t_list **stack_b, int pushed);

// Movements
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);

#endif

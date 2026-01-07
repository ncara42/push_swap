/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 22:08:10 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/07 21:53:53 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"

typedef enum e_option
{
	UNKNOWN,
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	BENCH
}	t_optype;

typedef struct s_options
{
	t_optype	*options;
	int			count;
}	t_options;

typedef struct s_stacks
{
	t_list	**stack_a;
	t_list	**stack_b;
}	t_stacks;

typedef struct s_stats
{
	size_t			ra_count;
	size_t			rb_count;
	size_t			rr_count;
	size_t			rra_count;
	size_t			rrb_count;
	size_t			rrr_count;
	size_t			pa_count;
	size_t			pb_count;
	size_t			sa_count;
	size_t			sb_count;
	size_t			ss_count;
	size_t			total_count;
	t_optype		algo;
	int				isbench;
	int				isadaptive;
	float			di;
}	t_stats;

// Functions
int				ft_strcmp(char *s1, char *s2);
char			**ft_split(char const *s, char c);
t_list			*ft_lstnew(long value);
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);
long			ft_atol(char *argv_char);
void			free_list(t_list *stack_a);
size_t			ft_strlen(const char *str);
void			free_split(char **split);
void			free_all(t_list **stack_a, t_list **stack_b,
					t_options **options);
void			sort_three_a(t_list **stack_a, t_stats **stats);
void			sort_three_top(t_stacks s, t_stats **stats);
void			sort_three_top_next(t_stacks s, t_stats **stats);
void			sort_three_top_next_next(t_stacks s, t_stats **stats);
void			sort_three(t_stacks s, int pushed,
					t_stats **stats);
void			sort_three_b(t_stacks s, int len,
					t_stats **stats);
void			ft_bzero(void *p, size_t i);
void			ft_putnbr(int n);

// Options parsing
int				parse_options(int argc, char **argv, t_options **options);
t_optype		which_option(char *optionstr);
int				verify_options(t_options **options);
void			adaptive(t_stacks s, t_options **options);
float			disorder_index(int len, t_list *stack);
void			which_algo(t_optype opt, t_stacks s,
					t_stats **stats);

// Simple
void			simple(t_list **stack_a, t_list **stack_b);
int				get_min(t_list *stack_a);

// Medium
void			medium(t_list **stack_a, t_list **stack_b);

	// Complex
void			complex(t_stacks s, int len);
void			complex_b(t_stacks s, int pushed);
int				complex_a_next(t_stacks s, int len, long pivot);
int				complex_b_next(t_stacks s, int len, long pivot);

// BENCH
void			print_bench_info(t_stats **stats, float d, t_optype opt);
void			bench_simple(t_list **stack_a, t_list **stack_b,
					int adapt);
void			bench_complex(t_stacks s, int len,
					float d, t_stats **stats, int adapt, int print);
int				bench_complex_a_next(t_list **stack_a, t_list **stack_b,
					int len, long pivot, t_stats **stats);
void			bench_complex_b(t_list **stack_a, t_list **stack_b, int len,
					float d, t_stats **stats, int adapt);
int				bench_complex_b_next(t_list **stack_a, t_list **stack_b,
					int len, long pivot, t_stats **stats);
void			count_bench(t_stats **stats);

// Movements
void			rra(t_list **stack_a, int bench);
void			rrb(t_list **stack_b, int bench);
void			ra(t_list **stack_a, int bench);
void			rb(t_list **stack_b, int bench);
void			pb(t_list **stack_a, t_list **stack_b, int bench);
void			pa(t_list **stack_a, t_list **stack_b, int bench);
void			sa(t_list **stack_a, int bench);
void			sb(t_list **stack_b, int bench);
void			ss(t_list **stack_a, t_list **stack_b, int bench);

#endif

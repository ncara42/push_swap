/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 22:08:10 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/06 19:58:57 by admin            ###   ########.fr       */
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
	int				count;
}	t_options;

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
}	t_stats;

// Functions
int				check_num(char **argv);
int				check_minmax(char **argv);
int				ft_strcmp(char *s1, char *s2);
char			**ft_split(char const *s, char c);
t_list			*ft_lstnew(long value);
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);
long			ft_atol(char *argv_char);
size_t			int_sqrt(size_t n);
void			free_list(t_list *stack_a);
size_t			ft_strlen(const char *str);
void			free_split(char **split);
void			freeall(t_list **stack_a, t_list **stack_b,
					t_options **options);
long			*getsortedarr(t_list *stack, int len);
void			bubblesort(long	*arr, size_t size);
void			sort_three_a(t_list **stack_a, int bench, t_stats **stats);
void			sort_three_top(t_list **stack, t_list **stack2,
					int bench, t_stats **stats);
void			sort_three_top_next(t_list **stack, t_list **stack2,
					int bench, t_stats **stats);
void			sort_three_top_next_next(t_list **stack, t_list **stack2,
					int bench, t_stats **stats);
void			sort_three(t_list **stack_a, t_list **stack_b, int pushed,
					int bench, t_stats **stats);
void			sort_three_b(t_list **stack_a, t_list **stack_b, int len,
					int bench, t_stats **stats);
void			ft_bzero(void *p, size_t i);
void			ft_putnbr(int n);

// Options parsing
int				parseoptions(int argc, char **argv, t_options **options);
t_optype		whichoption(char *optionstr);
int				verifyoptions(t_options **options);
int				parseoptions(int argc, char **argv, t_options **options);
void			adaptive(t_list **stack_a, t_list **stack_b,
					t_options **options);
float			index_error(int len, t_list *stack);
void			whichalgo(t_optype opt, int bench, t_list **a, t_list **b,
					int adapt);

// Simple
void			simple(t_list **stack_a, t_list **stack_b);
int				get_min(t_list *stack_a);

// Medium
void			medium(t_list **stack_a, t_list **stack_b);

	// Complex
void			complex(t_list **stack_a, t_list **stack_b, int len);
void			complex_b(t_list **stack_a, t_list **stack_b, int pushed);
int				complex_a_next(t_list **stack_a, t_list **stack_b,
					int len, long pivot);
int				complex_b_next(t_list **stack_a, t_list **stack_b,
					int len, long pivot);

// BENCH
void			printbenchinfo(t_stats **stats, float d, t_optype opt);
void			bench_simple(t_list **stack_a, t_list **stack_b, float d,
					int adapt);
void			bench_complex(t_list **stack_a, t_list **stack_b, int len,
					float d, t_stats **s, int adapt, int print);
int				bench_complex_a_next(t_list **stack_a, t_list **stack_b,
					int len, long pivot, t_stats **stats);
void			bench_complex_b(t_list **stack_a, t_list **stack_b, int len,
					float d, t_stats **stats, int adapt);
int				bench_complex_b_next(t_list **stack_a, t_list **stack_b,
					int len, long pivot, t_stats **stats);
void			gettotalcount(t_stats **stats);

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

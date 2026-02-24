/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 01:42:01 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/12 19:25:54 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bench_complex_next(t_stacks s, t_stats **stats, int len, int print)
{
	long	pivot;
	long	*arr;
	int		pushed;

	arr = array_sort(*(s.stack_a), len);
	if (!arr)
		return ;
	pivot = arr[len / 2];
	free(arr);
	pushed = bench_complex_a_next(s, len, pivot, stats);
	bench_complex(s, stats, len - pushed, 0);
	bench_complex_b(s, pushed, stats);
	(void)print;
}

void	bench_complex(t_stacks s, t_stats **stats, int len, int print)
{
	if (!s.stack_a || !*s.stack_a)
		return ;
	if ((*stats)->isadaptive)
		(*stats)->algo = ADAPTIVE;
	else
		(*stats)->algo = COMPLEX;
	if (len <= 3)
	{
		sort_three(s, len, stats);
		if (print)
		{
			count_bench(stats);
			print_bench_info(stats, COMPLEX);
		}
		return ;
	}
	bench_complex_next(s, stats, len, print);
	if (print)
	{
		count_bench(stats);
		print_bench_info(stats, COMPLEX);
	}
}

int	bench_complex_a_next(t_stacks s, int len, long pivot, t_stats **stats)
{
	int		i;
	int		pushed;
	int		ra_count;

	i = 0;
	pushed = 0;
	ra_count = 0;
	while (i < len && *(s.stack_a))
	{
		if ((*(s.stack_a))->content <= pivot)
		{
			pb(s.stack_a, s.stack_b);
			(*stats)->pb_count++;
			pushed++;
		}
		else if ((*(s.stack_a))->content > pivot)
		{
			ra(s.stack_a);
			(*stats)->ra_count++;
			ra_count++;
		}
		i++;
	}
	restore_a_stack(s.stack_a, ra_count, stats);
	return (pushed);
}

void	bench_complex_b(t_stacks s, int len, t_stats **stats)
{
	long	pivot;
	long	*arr;
	int		pushed;

	pushed = 0;
	if (len <= 3)
	{
		sort_three_b(s, len, stats);
		return ;
	}
	arr = array_sort(*(s.stack_b), len);
	if (!arr)
		return ;
	pivot = arr[len / 2];
	free(arr);
	pushed = bench_complex_b_next(s, len, pivot, stats);
	bench_complex(s, stats, pushed, 0);
	bench_complex_b(s, len - pushed, stats);
}

int	bench_complex_b_next(t_stacks s, int len, long pivot, t_stats **stats)
{
	int	i;
	int	pushed;
	int	rb_count;

	i = 0;
	rb_count = 0;
	pushed = 0;
	while (i < len && *(s.stack_b))
	{
		if ((*(s.stack_b))->content >= pivot)
		{
			pa(s.stack_a, s.stack_b);
			(*stats)->pa_count++;
			pushed++;
		}
		else if ((*(s.stack_b))->content < pivot)
		{
			rb(s.stack_b);
			(*stats)->rb_count++;
			rb_count++;
		}
		i++;
	}
	restore_b_stack(s.stack_b, rb_count, stats);
	return (pushed);
}

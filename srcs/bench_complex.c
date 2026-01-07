/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:49:03 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/07 20:34:21 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bench_complex(t_list **stack_a, t_list **stack_b,
			t_stats **stats, int print)
{
	long	pivot;
	long	*arr;
	int		pushed;

	if (!stack_a || !*stack_a)
		return ;
	if ((*stats)->sizea <= 3)
	{
		sort_three(stack_a, stack_b, (*stats)->sizea, 1, stats);
		if (print)
		{
			if ((*stats)->isadaptive)
				stats->algo = ADAPTIVE;
			else
				stats->algo = COMPLEX;
			count_bench(stats);
			print_bench_info(stats, COMPLEX);
		}
		return ;
	}
	arr = array_sort(*stack_a, (*stats)->sizea);
	if (!arr)
		return ;
	pivot = arr[(*stats)->sizea / 2];
	free(arr);
	pushed = bench_complex_a_next(stack_a, stack_b, len, pivot, &stats);
	bench_complex(stack_a, stack_b, len - pushed, d, &stats, adapt, 0);
	bench_complex_b(stack_a, stack_b, pushed, d, &stats, adapt);
	if (adapt)
		stats->algo = ADAPTIVE;
	else
		stats->algo = COMPLEX;
	if (print)
	{
		count_bench(&stats);
		print_bench_info(&stats, d, COMPLEX);
	}
}

int	bench_complex_a_next(t_list **stack_a, t_list **stack_b, int len,
			long pivot, t_stats **stats)
{
	int		i;
	int		pushed;
	int		ra_count;

	i = 0;
	pushed = 0;
	ra_count = 0;
	while (i < len)
	{
		if ((*stack_a)->content <= pivot)
		{
			pb(stack_a, stack_b, 1);
			(*stats)->pb_count++;
			pushed++;
		}
		else if ((*stack_a)->content > pivot)
		{
			ra(stack_a, 1);
			(*stats)->ra_count++;
			ra_count++;
		}
		i++;
	}
	while (ra_count-- > 0)
	{
		rra(stack_a, 1);
		(*stats)->rra_count++;
	}
	return (pushed);
}

void	bench_complex_b(t_list **stack_a, t_list **stack_b,
			int len, float d, t_stats **stats, int adapt)
{
	long	pivot;
	long	*arr;
	int		pushed;

	pushed = 0;
	if (len <= 3)
	{
		sort_three_b(stack_a, stack_b, len, 1, stats);
		return ;
	}
	arr = array_sort(*stack_b, len);
	if (!arr)
		return ;
	pivot = arr[len / 2];
	free(arr);
	pushed = bench_complex_b_next(stack_a, stack_b, len, pivot, stats);
	bench_complex(stack_a, stack_b, pushed, d, stats, adapt, 0);
	bench_complex_b(stack_a, stack_b, len - pushed, d, stats, adapt);
}

int	bench_complex_b_next(t_list **stack_a, t_list **stack_b, int len,
			long pivot, t_stats **stats)
{
	int		i;
	int		pushed;
	int		rb_count;

	i = 0;
	rb_count = 0;
	pushed = 0;
	while (i < len)
	{
		if ((*stack_b)->content >= pivot)
		{
			pa(stack_a, stack_b, 1);
			(*stats)->pa_count++;
			pushed++;
		}
		else if ((*stack_b)->content < pivot)
		{
			rb(stack_b, 1);
			(*stats)->rb_count++;
			rb_count++;
		}
		i++;
	}
	while (rb_count-- > 0)
	{
		rrb(stack_b, 1);
		(*stats)->rrb_count++;
	}
	return (pushed);
}

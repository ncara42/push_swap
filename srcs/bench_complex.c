/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:49:03 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/07 21:53:00 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bench_complex(t_stacks s,
			t_stats **stats, int print)
{
	long	pivot;
	long	*arr;
	int		pushed;

	if (!s.stack_a || !*s.stack_a)
		return ;
	if ((*stats)->sizea <= 3)
	{
		sort_three(s, (*stats)->sizea, stats);
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
	arr = array_sort(*s.stack_a, (*stats)->sizea);
	if (!arr)
		return ;
	pivot = arr[(*stats)->sizea / 2];
	free(arr);
	pushed = bench_complex_a_next(s, len, pivot, &stats);
	bench_complex(s, len - pushed, d, &stats, adapt, 0);
	bench_complex_b(s, pushed, d, &stats, adapt);
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

int	bench_complex_a_next(t_stacks s, int len,
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
		if ((*s.stack_a)->content <= pivot)
		{
			pb(s.stack_a, s.stack_b, 1);
			(*stats)->pb_count++;
			pushed++;
		}
		else if ((*s.stack_a)->content > pivot)
		{
			ra(s.stack_a, 1);
			(*stats)->ra_count++;
			ra_count++;
		}
		i++;
	}
	while (ra_count-- > 0)
	{
		rra(s.stack_a, 1);
		(*stats)->rra_count++;
	}
	return (pushed);
}

void	bench_complex_b(t_stacks s,
			int len, float d, t_stats **stats, int adapt)
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
	arr = array_sort(*s.stack_b, len);
	if (!arr)
		return ;
	pivot = arr[len / 2];
	free(arr);
	pushed = bench_complex_b_next(s, len, pivot, stats);
	bench_complex(s, pushed, d, stats, adapt, 0);
	bench_complex_b(s, len - pushed, d, stats, adapt);
}

int	bench_complex_b_next(t_stacks s, int len,
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
		if ((*s.stack_b)->content >= pivot)
		{
			pa(s.stack_a, s.stack_b, 1);
			(*stats)->pa_count++;
			pushed++;
		}
		else if ((*s.stack_b)->content < pivot)
		{
			rb(s.stack_b, 1);
			(*stats)->rb_count++;
			rb_count++;
		}
		i++;
	}
	while (rb_count-- > 0)
	{
		rrb(s.stack_b, 1);
		(*stats)->rrb_count++;
	}
	return (pushed);
}

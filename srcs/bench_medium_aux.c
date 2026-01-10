/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_medium_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 16:59:26 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/10 23:18:01 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bench_medium_pushing_to_a(t_stacks s, int bench, t_stats **stats)
{
	int	max_pos;
	int	size;

	while (*s.stack_b)
	{
		max_pos = get_max_pos(*s.stack_b);
		size = ft_lstsize(*s.stack_b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
			{
				rb(s.stack_b);
				if (bench)
					(*stats)->rb_count++;
			}
		}
		else
		{
			max_pos = size - max_pos;
			while (max_pos--)
			{
				rrb(s.stack_b);
				if (bench)
					(*stats)->rrb_count++;
			}
		}
		pa(s.stack_a, s.stack_b);
		if (bench)
			(*stats)->pa_count++;
	}
}

void	bench_medium_nearest_num(t_stacks s, long *arr, int bench,
			t_stats **stats)
{
	int	top;
	int	bottom;
	int	size;
	int	pivot;

	top = get_top_pos(*s.stack_a, arr, s.start, s.end);
	bottom = get_bottom_pos(*s.stack_a, arr, s.start, s.end);
	size = ft_lstsize(*s.stack_a);
	if (top <= size - bottom)
	{
		while (top-- > 0)
		{
			ra(s.stack_a);
			if (bench)
				(*stats)->ra_count++;
		}
	}
	else
	{
		bottom = size - bottom;
		while (bottom-- > 0)
		{
			rra(s.stack_a);
			if (bench)
				(*stats)->rra_count++;
		}
	}
	pb(s.stack_a, s.stack_b);
	if (bench)
		(*stats)->pb_count++;
	pivot = s.start + (s.end - s.start) / 2;
	if (ft_lstsize(*s.stack_b) > 1 && (*s.stack_b)->content < arr[pivot])
	{
		rb(s.stack_b);
		if (bench)
			(*stats)->rb_count++;
	}
}

void	bench_medium_get_chunks(t_stacks s, long *arr, int bench,
			t_stats **stats)
{
	int	chunks;
	int	total_size;
	int	size;
	int	i;

	total_size = ft_lstsize(*s.stack_a);
	chunks = get_n_chunks(total_size);
	size = total_size / chunks;
	i = 0;
	while (i < chunks)
	{
		s.start = i * size;
		if (i == chunks - 1)
			s.end = total_size - 1;
		else
			s.end = s.start + size - 1;
		while (in_range(*s.stack_a, arr, s.start, s.end))
			bench_medium_nearest_num(s, arr, bench, stats);
		i++;
	}
}

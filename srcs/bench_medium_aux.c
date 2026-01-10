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
				if (bench)
				{
					rb(s.stack_b, 1);
					(*stats)->rb_count++;
				}
				else
					rb(s.stack_b, 0);
			}
		}
		else
		{
			max_pos = size - max_pos;
			while (max_pos--)
			{
				if (bench)
				{
					rrb(s.stack_b, 1);
					(*stats)->rrb_count++;
				}
				else
					rrb(s.stack_b, 0);
			}
		}
		if (bench)
		{
			pa(s.stack_a, s.stack_b, 1);
			(*stats)->pa_count++;
		}
		else
			pa(s.stack_a, s.stack_b, 0);
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
			if (bench)
			{
				ra(s.stack_a, 1);
				(*stats)->ra_count++;
			}
			else
				ra(s.stack_a, 0);
		}
	}
	else
	{
		bottom = size - bottom;
		while (bottom-- > 0)
		{
			if (bench)
			{
				rra(s.stack_a, 1);
				(*stats)->rra_count++;
			}
			else
				rra(s.stack_a, 0);
		}
	}
	if (bench)
	{
		pb(s.stack_a, s.stack_b, 1);
		(*stats)->pb_count++;
	}
	else
		pb(s.stack_a, s.stack_b, 0);
	pivot = s.start + (s.end - s.start) / 2;
	if (ft_lstsize(*s.stack_b) > 1 && (*s.stack_b)->content < arr[pivot])
	{
		if (bench)
		{
			rb(s.stack_b, 1);
			(*stats)->rb_count++;
		}
		else
			rb(s.stack_b, 0);
	}
}

void	bench_medium_get_chunks(t_stacks s, long *arr, int bench,
			t_stats **stats)
{
	int chunks;
	int total_size;
	int size;
	int i;

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
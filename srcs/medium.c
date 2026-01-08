/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:32:15 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/08 20:13:16 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_n_chunks(int n)
{
	if (n <= 5)
		return (1);
	else if (n <= 50)
		return (2);
	else if (n <= 100)
		return (6);
	else if (n <= 500)
		return (9);
	return (11);
}

int	get_top_pos(t_list *stack_a, long *arr, int start, int end)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->content >= arr[start] && stack_a->content <= arr[end])
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (-1);
}

int	get_bottom_pos(t_list *stack_a, long *arr, int start, int end)
{
	int	i;
	int	bottom;

	i = 0;
	bottom = -1;
	while (stack_a)
	{
		if (stack_a->content >= arr[start] && stack_a->content <= arr[end])
			bottom = i;
		stack_a = stack_a->next;
		i++;
	}
	return (bottom);
}

void	nearest_num(t_stacks s, long *arr, int bench, t_stats **stats)
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

int	in_range(t_list *stack_a, long *arr, int start, int end)
{
	while (stack_a)
	{
		if (stack_a->content >= arr[start] && stack_a->content <= arr[end])
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	get_chunks(t_stacks s, long *arr, int bench, t_stats **stats)
{
	int	chunks;
	int	size;
	int	i;

	chunks = get_n_chunks(ft_lstsize(*s.stack_a));
	size = ft_lstsize(*s.stack_a) / chunks;
	i = 0;
	while (i < chunks)
	{
		s.start = i * size;
		if (i == chunks - 1)
			s.end = size - 1;
		else
			s.end = s.start + size - 1;
		while (in_range(*s.stack_a, arr, s.start, s.end))
			nearest_num(s, arr, bench, stats);
		i++;
	}
}

int	get_max_pos(t_list *stack_b)
{
	int	pos;
	int	max_pos;
	int	max_val;

	pos = 0;
	max_pos = 0;
	max_val = stack_b->content;
	while (stack_b)
	{
		if (stack_b->content > max_val)
		{
			max_val = stack_b->content;
			max_pos = pos;
		}
		stack_b = stack_b->next;
		pos++;
	}
	return (max_pos);
}

void	pushing_to_a(t_stacks s, int bench, t_stats **stats)
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

void	medium(t_stacks s)
{
	long	*arr;
	int		size;

	size = ft_lstsize(*s.stack_a);
	if (size == 1)
		return ;
	arr = array_sort(*s.stack_a, size);
	if (!arr)
		return ;
	get_chunks(s, arr, 0, NULL);
	pushing_to_a(s, 0, NULL);
	free(arr);
}

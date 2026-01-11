/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 16:59:10 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/11 17:52:42 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	nearest_num(t_stacks s, long *arr)
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
			ra(s.stack_a);
	}
	else
	{
		bottom = size - bottom;
		while (bottom-- > 0)
			rra(s.stack_a);
	}
	pb(s.stack_a, s.stack_b);
	pivot = s.start + (s.end - s.start) / 2;
	if (ft_lstsize(*s.stack_b) > 1 && (*s.stack_b)->content < arr[pivot])
		rb(s.stack_b);
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

void	pushing_to_a(t_stacks s)
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
				rb(s.stack_b);
		}
		else
		{
			max_pos = size - max_pos;
			while (max_pos--)
				rrb(s.stack_b);
		}
		pa(s.stack_a, s.stack_b);
	}
}

void	medium(t_stacks s)
{
	long	*arr;
	int		size;
	float	desorden;

	size = ft_lstsize(*s.stack_a);
	if (size == 1)
		return ;
	desorden = disorder_index(size, *s.stack_a);
	if (desorden == 0)
		return ;
	arr = array_sort(*s.stack_a, size);
	if (!arr)
		return ;
	get_chunks(s, arr);
	pushing_to_a(s);
	free(arr);
}

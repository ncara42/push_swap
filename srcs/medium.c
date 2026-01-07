/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:32:15 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/07 15:59:23 by ncaravac         ###   ########.fr       */
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

void	nearest_num(t_list **stack_a, t_list **stack_b, long *arr,
			int start, int end)
{
	int	top;
	int	bottom;
	int	size;
	int	pivot;

	top = get_top_pos(*stack_a, arr, start, end);
	bottom = get_bottom_pos(*stack_a, arr, start, end);
	size = ft_lstsize(*stack_a);
	if (top <= size - bottom)
	{
		while (top-- > 0)
			ra(stack_a, 0);
	}
	else
	{
		bottom = size - bottom;
		while (bottom-- > 0)
			rra(stack_a, 0);
	}
	pb(stack_a, stack_b, 0);
	pivot = start + (end - start) / 2;
	if (ft_lstsize(*stack_b) > 1 && (*stack_b)->content < arr[pivot])
		rb(stack_b, 0);
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

void	get_chunks(t_list **stack_a, t_list **stack_b, long *arr, int n)
{
	int	chunks;
	int	size;
	int	start;
	int	end;
	int	i;

	chunks = get_n_chunks(n);
	size = n / chunks;
	i = 0;
	while (i < chunks)
	{
		start = i * size;
		if (i == chunks - 1)
			end = n - 1;
		else
			end = start + size - 1;
		while (in_range(*stack_a, arr, start, end))
			nearest_num(stack_a, stack_b, arr, start, end);
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

void	pushing_to_a(t_list **stack_a, t_list **stack_b)
{
	int	max_pos;
	int	size;

	while (*stack_b)
	{
		max_pos = get_max_pos(*stack_b);
		size = ft_lstsize(*stack_b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(stack_b, 0);
		}
		else
		{
			max_pos = size - max_pos;
			while (max_pos--)
				rrb(stack_b, 0);
		}
		pa(stack_a, stack_b, 0);
	}
}

void	medium(t_list **stack_a, t_list **stack_b)
{
	long	*arr;
	int		size;

	size = ft_lstsize(*stack_a);
	arr = array_sort(*stack_a, size);
	if (!arr)
		return ;
	get_chunks(stack_a, stack_b, arr, size);
	pushing_to_a(stack_a, stack_b);
	free(arr);
}

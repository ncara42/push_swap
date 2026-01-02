/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-ach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:16:56 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/02 16:21:02 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complex(t_list **stack_a, t_list **stack_b, int len)
{
	long	pivot;
	long	*arr;
	int		i;
	int		pushed;
	int		ra_count;

	if (len <= 3)
	{
		sort_three_complex(stack_a, stack_b, len);
		return ;
	}
	arr = getsortedarr(*stack_a, len);
	if (!arr)
		return ;
	pivot = arr[len / 2];
	free(arr);
	i = 0;
	pushed = 0;
	ra_count = 0;
	while (i < len)
	{
		if ((*stack_a)->content <= pivot)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else if ((*stack_a)->content > pivot)
		{
			ra(stack_a);
			ra_count++;
		}
		i++;
	}
	while (ra_count > 0)
	{
		rra(stack_a);
		ra_count--;
	}
	complex(stack_a, stack_b, len - pushed);
	complex_b(stack_a, stack_b, pushed);
}

void	complex_b(t_list **stack_a, t_list **stack_b, int len)
{
	long	pivot;
	long	*arr;
	int		i;
	int		pushed;
	int		rb_count;

	if (len <= 3)
	{
		sort_three_b(stack_a, stack_b, len);
		return ;
	}
	arr = getsortedarr(*stack_b, len);
	if (!arr)
		return ;
	pivot = arr[len / 2];
	free(arr);
	i = 0;
	rb_count = 0;
	pushed = 0;
	while (i < len)
	{
		if ((*stack_b)->content >= pivot)
		{
			pa(stack_a, stack_b);
			pushed++;
		}
		else if ((*stack_b)->content < pivot)
		{
			rb(stack_b);
			rb_count++;
		}
		i++;
	}
	while (rb_count > 0)
	{
		rrb(stack_b);
		rb_count--;
	}
	complex(stack_a, stack_b, pushed);
	complex_b(stack_a, stack_b, len - pushed);
}

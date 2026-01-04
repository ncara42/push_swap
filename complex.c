/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:16:56 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/04 15:35:30 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complex(t_list **stack_a, t_list **stack_b, int len)
{
	long	pivot;
	long	*arr;
	int		pushed;

	if (len <= 3)
	{
		sort_three(stack_a, stack_b, len);
		return ;
	}
	arr = getsortedarr(*stack_a, len);
	if (!arr)
		return ;
	pivot = arr[len / 2];
	free(arr);
	pushed = complex_a_next(stack_a, stack_b, len, pivot);
	complex(stack_a, stack_b, len - pushed);
	complex_b(stack_a, stack_b, pushed);
}

int	complex_a_next(t_list **stack_a, t_list **stack_b, int len, long pivot)
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
	while (ra_count-- > 0)
		rra(stack_a);
	return (pushed);
}

void	complex_b(t_list **stack_a, t_list **stack_b, int len)
{
	long	pivot;
	long	*arr;
	int		pushed;

	pushed = 0;
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
	pushed = complex_b_next(stack_a, stack_b, len, pivot);
	complex(stack_a, stack_b, pushed);
	complex_b(stack_a, stack_b, len - pushed);
}

int	complex_b_next(t_list **stack_a, t_list **stack_b, int len, long pivot)
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
	while (rb_count-- > 0)
		rrb(stack_b);
	return (pushed);
}

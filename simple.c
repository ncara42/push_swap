/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 13:45:46 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/04 15:33:45 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list *stack_a)
{
	int	min;
	int	pos_min;
	int	pos_current;

	if (!stack_a)
		return (0);
	min = stack_a->content;
	pos_min = 0;
	pos_current = 0;
	while (stack_a)
	{
		if (stack_a->content < min)
		{
			min = stack_a->content;
			pos_min = pos_current;
		}
		stack_a = stack_a->next;
		pos_current++;
	}
	return (pos_min);
}

void	simple(t_list **stack_a, t_list **stack_b)
{
	int	nodes;
	int	pos_min;

	while (ft_lstsize(*stack_a) > 3)
	{
		pos_min = get_min(*stack_a);
		nodes = ft_lstsize(*stack_a);
		if (pos_min <= nodes / 2)
		{
			while (pos_min--)
				ra(stack_a);
		}
		else
		{
			while (nodes - pos_min++)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three_a(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

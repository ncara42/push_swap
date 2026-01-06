/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 13:45:46 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/06 13:22:21 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
				ra(stack_a, 0);
		}
		else
		{
			while (nodes - pos_min++)
				rra(stack_a, 0);
		}
		pb(stack_a, stack_b, 0);
	}
	if (ft_lstsize(*stack_a) >= 3)
		sort_three_a(stack_a, 0, NULL);
	else
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a, 0);
	while (*stack_b)
		pa(stack_a, stack_b, 0);
}

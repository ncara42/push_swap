/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_complex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-ach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:58:54 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/02 18:02:41 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_top(t_list **stack, t_list **stack2)
{
	long	first;
	long	second;
	long	third;

	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second < third && first > third)
	{
		sa(stack);
		pb(stack, stack2);
		sa(stack);
		pa(stack, stack2);
	}
	else if (first < second && second > third && first > third)
	{
		pb(stack, stack2);
		sa(stack);
		pa(stack, stack2);
		sa(stack);
	}
	else if (first < second && second > third && first < third)
	{
		pb(stack, stack2);
		sa(stack);
		pa(stack, stack2);
	}
	else if (first > second && second > third)
	{
		sa(stack);
		pb(stack, stack2);
		sa(stack);
		pa(stack, stack2);
		sa(stack);
	}
}

void	sort_three_b(t_list **stack_a, t_list **stack_b, int len)
{
	if (len == 1)
		pa(stack_a, stack_b);
	else if (len == 2)
	{
		if ((*stack_b)->content < (*stack_b)->next->content)
			sb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else if (len == 3)
	{
		while (len--)
			pa(stack_a, stack_b);
		sort_three_top(stack_a, stack_b);
	}
}

void	sort_three_complex(t_list **stack, t_list **stack2, int pushed)
{
	if (pushed == 3 && ft_lstsize(*stack) == 3)
		sort_three(stack);
	else if (pushed == 3)
		sort_three_top(stack, stack2);
	else if (pushed == 2)
	{
		if ((*stack)->content > (*stack)->next->content)
			sa(stack);
	}
}

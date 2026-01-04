/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:58:54 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/04 15:31:37 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_top(t_list **stack, t_list **stack2)
{
	sort_three_top_next(stack, stack2);
	sort_three_top_next_next(stack, stack2);
}

void	sort_three_top_next(t_list **stack, t_list **stack2)
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
}

void	sort_three_top_next_next(t_list **stack, t_list **stack2)
{
	long	first;
	long	second;
	long	third;

	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (first < second && second > third && first < third)
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

void	sort_three(t_list **stack, t_list **stack2, int pushed)
{
	if (pushed == 3 && ft_lstsize(*stack) == 3)
		sort_three_a(stack);
	else if (pushed == 3)
		sort_three_top(stack, stack2);
	else if (pushed == 2)
	{
		if ((*stack)->content > (*stack)->next->content)
			sa(stack);
	}
}

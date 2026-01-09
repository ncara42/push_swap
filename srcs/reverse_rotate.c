/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-ach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:18:10 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/09 18:24:48 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrb(t_list **stack_b, int bench)
{
	t_list	*last;
	t_list	*tmp;

	tmp = *stack_b;
	while (tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
	tmp->next = *stack_b;
	*stack_b = tmp;
	if (!bench)
		write(1, "rrb\n", 4);
}

void	rra(t_list **stack_a, int bench)
{
	t_list	*last;
	t_list	*tmp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	while (tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
	if (!bench)
		write(1, "rra\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b, int print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print)
		write(1, "rrr\n", 4);
}

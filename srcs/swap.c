/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 02:21:05 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/05 22:32:32 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_list **stack_a, int bench)
{
	swap(stack_a);
	if (!bench)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack_b, int bench)
{
	swap(stack_b);
	if (!bench)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, int bench)
{
	swap(stack_a);
	swap(stack_b);
	if (!bench)
		write(1, "ss\n", 3);
}

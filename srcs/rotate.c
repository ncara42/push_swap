/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:54:56 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/06 09:44:42 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_list **stack_a, int bench)
{
	t_list	*first;
	t_list	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	first->next = NULL;
	last = ft_lstlast(*stack_a);
	last->next = first;
	if (!bench)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, int bench)
{
	t_list	*first;
	t_list	*last;

	first = *stack_b;
	*stack_b = first->next;
	first->next = NULL;
	last = ft_lstlast(*stack_b);
	last->next = first;
	if (!bench)
		write(1, "rb\n", 3);
}

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

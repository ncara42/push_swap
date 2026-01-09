/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:54:56 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/09 18:19:00 by vvan-ach         ###   ########.fr       */
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

void	rr(t_list **stack_a, t_list **stack_b, int print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print)
		write(1, "rr\n", 3);
}

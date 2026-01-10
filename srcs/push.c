/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:54:13 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/10 23:11:26 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!*stack_a || !stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "pb\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!*stack_b || !stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
}

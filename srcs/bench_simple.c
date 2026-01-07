/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:20:57 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/07 20:24:45 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bench_simple(t_list **stack_a, t_list **stack_b, t_stats **stats)
{
	int		nodes;
	int		pos_min;

	while (ft_lstsize(*stack_a) > 3)
	{
		pos_min = get_min(*stack_a);
		nodes = ft_lstsize(*stack_a);
		if (pos_min <= nodes / 2)
		{
			while (pos_min--)
			{
				ra(stack_a, 1);
				(*stats)->ra_count++;
			}
		}
		else
		{
			while (nodes - pos_min++)
			{
				rra(stack_a, 1);
				(*stats)->rra_count++;
			}
		}
		pb(stack_a, stack_b, 1);
		(*stats)->pb_count++;
	}
	if (ft_lstsize(*stack_a) >= 3)
		sort_three_a(stack_a, 1, stats);
	else
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
		{
			sa(stack_a, 1);
			(*stats)->sa_count++;
		}
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b, 1);
		(*stats)->pa_count++;
	}
	if (adapt)
		(*stats)->algo = ADAPTIVE;
	else
		(*stats)->algo = SIMPLE;
	count_bench(stats);
	print_bench_info(stats, SIMPLE);
}

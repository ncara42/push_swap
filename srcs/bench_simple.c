/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:20:57 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/07 23:58:29 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bench_simple(t_stacks s, t_stats **stats)
{
	int		nodes;
	int		pos_min;

	while (ft_lstsize(*s.stack_a) > 3)
	{
		pos_min = get_min(*s.stack_a);
		nodes = ft_lstsize(*s.stack_a);
		if (pos_min <= nodes / 2)
		{
			while (pos_min--)
			{
				ra(s.stack_a, 1);
				(*stats)->ra_count++;
			}
		}
		else
		{
			while (nodes - pos_min++)
			{
				rra(s.stack_a, 1);
				(*stats)->rra_count++;
			}
		}
		pb(s.stack_a, s.stack_b, 1);
		(*stats)->pb_count++;
	}
	if (ft_lstsize(*s.stack_a) >= 3)
		sort_three_a(s.stack_a, stats);
	else
	{
		if ((*s.stack_a)->content > (*s.stack_a)->next->content)
		{
			sa(s.stack_a, 1);
			(*stats)->sa_count++;
		}
	}
	while (*s.stack_b)
	{
		pa(s.stack_a, s.stack_b, 1);
		(*stats)->pa_count++;
	}
	if ((*stats)->isadaptive)
		(*stats)->algo = ADAPTIVE;
	else
		(*stats)->algo = SIMPLE;
	count_bench(stats);
	print_bench_info(stats, SIMPLE);
}

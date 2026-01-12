/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:20:57 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/12 19:05:19 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_ra(t_list **a, int *pos, t_stats *st)
{
	while ((*pos)-- > 0)
	{
		ra(a);
		st->ra_count++;
	}
}

static void	do_rra(t_list **a, int nodes, int *pos, t_stats *st)
{
	while (nodes - (*pos)++ > 0)
	{
		rra(a);
		st->rra_count++;
	}
}

static void	push_min(t_stacks s, int pos_min, int nodes, t_stats *st)
{
	if (pos_min <= nodes / 2)
		do_ra(s.stack_a, &pos_min, st);
	else
		do_rra(s.stack_a, nodes, &pos_min, st);
	pb(s.stack_a, s.stack_b);
	st->pb_count++;
}

static void	sort_small_a(t_stacks s, t_list **a, t_stats **stats)
{
	if (ft_lstsize(*a) >= 3)
		sort_three_a(a, stats, 1);
	else if ((*a)->content > (*a)->next->content)
	{
		sa(a);
		(*stats)->sa_count++;
	}
	while (*s.stack_b)
	{
		pa(s.stack_a, s.stack_b);
		(*stats)->pa_count++;
	}
	if ((*stats)->isadaptive)
		(*stats)->algo = ADAPTIVE;
	else
		(*stats)->algo = SIMPLE;
}

void	bench_simple(t_stacks s, t_stats **stats)
{
	int	nodes;
	int	pos_min;

	if (ft_lstsize(*s.stack_a) == 1)
	{
		print_bench_info(stats, SIMPLE);
		return ;
	}
	while (ft_lstsize(*s.stack_a) > 3)
	{
		pos_min = get_min(*s.stack_a);
		nodes = ft_lstsize(*s.stack_a);
		push_min(s, pos_min, nodes, *stats);
	}
	sort_small_a(s, s.stack_a, stats);
	count_bench(stats);
	print_bench_info(stats, SIMPLE);
}

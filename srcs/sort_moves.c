/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:58:54 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/11 05:00:22 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_moves_b(t_stacks s, t_stats **stats, int bench)
{
	if ((*(s.stack_b))->content < (*(s.stack_b))->next->content)
	{
		sb(s.stack_b);
		if (bench)
			(*stats)->sb_count++;
	}
	pa((s.stack_a), (s.stack_b));
	pa((s.stack_a), (s.stack_b));
	if (bench)
		(*stats)->pa_count += 2;
}

void	sort_moves_a(t_list **stack_a, t_stats **stats, t_fst fst, int bench)
{
	if (fst.first > fst.second && fst.second < fst.third
		&& fst.first < fst.third)
	{
		sa(stack_a);
		if (bench)
			(*stats)->sa_count++;
	}
	else if (fst.first > fst.second && fst.second > fst.third)
	{
		sa(stack_a);
		rra(stack_a);
		if (bench)
		{
			(*stats)->sa_count++;
			(*stats)->rra_count++;
		}
	}
	else if (fst.first > fst.second && fst.second < fst.third
		&& fst.first > fst.third)
	{
		ra(stack_a);
		if (bench)
			(*stats)->ra_count++;
	}
	sort_moves_a_next(stack_a, stats, fst, bench);
}

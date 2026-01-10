/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three-v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:24:03 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/10 23:30:14 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_moves_a_next(t_list **stack_a, t_stats **stats, t_fst fst,
			int bench)
{
	if (fst.first < fst.second && fst.second > fst.third
		&& fst.first < fst.third)
	{
		sa(stack_a);
		ra(stack_a);
		if (bench)
		{
			(*stats)->sa_count++;
			(*stats)->ra_count++;
		}
	}
	else if (fst.first < fst.second && fst.second > fst.third
		&& fst.first > fst.third)
	{
		rra(stack_a);
		if (bench)
			(*stats)->rra_count++;
	}
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

void	sort_three_a(t_list **stack_a, t_stats **stats, int bench)
{
	t_fst	fst;

	if (!stats || !*stats || !*stack_a || !(*stack_a)->next
		|| !(*stack_a)->next->next)
		return ;
	fst.first = (*stack_a)->content;
	fst.second = (*stack_a)->next->content;
	fst.third = (*stack_a)->next->next->content;
	sort_moves_a(stack_a, stats, fst, bench);
}

void	sort_moves_b_next(t_stacks s, int len, t_stats **stats, int bench)
{
	while (len--)
	{
		pa(s.stack_a, s.stack_b);
		if (bench)
			(*stats)->pa_count++;
	}
}

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

void	sort_three_b(t_stacks s, int len, t_stats **stats)
{
	t_fst	fst;
	int		bench;

	if (!stats || !*stats)
		bench = 0;
	else
		bench = (*stats)->isbench;
	if (len == 1 && bench)
	{
		pa(s.stack_a, s.stack_b);
		(*stats)->pa_count++;
	}
	else if (len == 1 && !bench)
		pa(s.stack_a, s.stack_b);
	else if (len == 2)
		sort_moves_b(s, stats, bench);
	else if (len == 3)
	{
		sort_moves_b_next(s, len, stats, bench);
		sort_three_top(s, stats, &fst, bench);
	}
}

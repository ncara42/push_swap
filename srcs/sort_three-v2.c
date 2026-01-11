/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three-v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:24:03 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/11 17:33:07 by vvan-ach         ###   ########.fr       */
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

void	sort_three_a(t_list **stack_a, t_stats **stats, int bench)
{
	t_fst	fst;

	if (ft_lstsize(*stack_a) == 1)
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

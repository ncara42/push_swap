/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three-v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:24:03 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/10 17:00:20 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_a(t_list **stack_a, t_stats **stats, int bench)
{
	t_fst	fst;

	if (!stats || !*stats)
		return ;
	if (!(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	fst.first = (*stack_a)->content;
	fst.second = (*stack_a)->next->content;
	fst.third = (*stack_a)->next->next->content;
	if (fst.first > fst.second && fst.second < fst.third
		&& fst.first < fst.third)
	{
		sa(stack_a, bench);
		(*stats)->sa_count++;
	}
	else if (fst.first > fst.second && fst.second > fst.third)
	{
		sa(stack_a, bench);
		rra(stack_a, bench);
		(*stats)->sa_count++;
		(*stats)->rra_count++;
	}
	else if (fst.first > fst.second && fst.second < fst.third
		&& fst.first > fst.third)
	{
		ra(stack_a, bench);
		(*stats)->ra_count++;
	}
	else if (fst.first < fst.second && fst.second > fst.third
		&& fst.first < fst.third)
	{
		sa(stack_a, bench);
		ra(stack_a, bench);
		(*stats)->sa_count++;
		(*stats)->ra_count++;
	}
	else if (fst.first < fst.second && fst.second > fst.third
		&& fst.first > fst.third)
	{
		rra(stack_a, bench);
		(*stats)->rra_count++;
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
		pa((s.stack_a), (s.stack_b), 1);
		(*stats)->pa_count++;
	}
	else if (len == 1 && !bench)
		pa((s.stack_a), (s.stack_b), 0);
	else if (len == 2)
	{
		if ((*(s.stack_b))->content < (*(s.stack_b))->next->content)
		{
			if (bench)
			{
				sb((s.stack_b), 1);
				(*stats)->sb_count++;
			}
			else
				sb((s.stack_b), 0);
		}
		if (bench)
		{
			pa((s.stack_a), (s.stack_b), 1);
			pa((s.stack_a), (s.stack_b), 1);
			(*stats)->pa_count += 2;
		}
		else
		{
			pa((s.stack_a), (s.stack_b), 0);
			pa((s.stack_a), (s.stack_b), 0);
		}
	}
	else if (len == 3)
	{
		while (len--)
		{
			if (bench)
			{
				pa((s.stack_a), (s.stack_b), 1);
				(*stats)->pa_count++;
			}
			else
				pa((s.stack_a), (s.stack_b), 0);
		}
		sort_three_top(s, stats, &fst, bench);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three-v1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:58:54 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/10 23:25:42 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_top(t_stacks s, t_stats **stats, t_fst *fst, int bench)
{
	fst->first = (*(s.stack_a))->content;
	fst->second = (*(s.stack_a))->next->content;
	fst->third = (*(s.stack_a))->next->next->content;
	sort_three_top_next(s, stats, fst, bench);
	sort_three_top_next_next(s, stats, fst, bench);
}

void	sort_three_top_next(t_stacks s, t_stats **stats, t_fst *fst, int bench)
{
	if (fst->first > fst->second && fst->second < fst->third
		&& fst->first < fst->third)
	{
		sa(s.stack_a);
		if (bench)
			(*stats)->sa_count++;
	}
	else if (fst->first > fst->second && fst->second < fst->third
		&& fst->first > fst->third)
	{
		sa(s.stack_a);
		pb(s.stack_a, s.stack_b);
		sa(s.stack_a);
		pa(s.stack_a, s.stack_b);
		if (bench)
		{
			(*stats)->sa_count += 2;
			(*stats)->pb_count++;
			(*stats)->pa_count++;
		}
	}
	else if (fst->first < fst->second && fst->second > fst->third
		&& fst->first > fst->third)
	{
		pb(s.stack_a, s.stack_b);
		sa(s.stack_a);
		pa(s.stack_a, s.stack_b);
		sa(s.stack_a);
		if (bench)
		{
			(*stats)->pb_count++;
			(*stats)->sa_count += 2;
			(*stats)->pa_count++;
		}
	}
}

void	sort_three_top_next_next(t_stacks s, t_stats **stats, t_fst *fst,
			int bench)
{
	if (fst->first < fst->second && fst->second > fst->third
		&& fst->first < fst->third)
	{
		pb(s.stack_a, s.stack_b);
		sa(s.stack_a);
		pa(s.stack_a, s.stack_b);
		if (bench)
		{
			(*stats)->pb_count++;
			(*stats)->sa_count++;
			(*stats)->pa_count++;
		}
	}
	else if (fst->first > fst->second
		&& fst->second > fst->third)
	{
		sa(s.stack_a);
		pb(s.stack_a, s.stack_b);
		sa(s.stack_a);
		pa(s.stack_a, s.stack_b);
		sa(s.stack_a);
		if (bench)
		{
			(*stats)->sa_count += 3;
			(*stats)->pb_count++;
			(*stats)->pa_count++;
		}
	}
}

void	sort_three(t_stacks s, int pushed, t_stats **stats)
{
	t_fst	fst;
	int		bench;

	if (!stats || !*stats)
		bench = 0;
	else
		bench = (*stats)->isbench;
	if (pushed == 3 && ft_lstsize(*(s.stack_a)) == 3)
		sort_three_a(s.stack_a, stats, bench);
	else if (pushed == 3)
		sort_three_top(s, stats, &fst, bench);
	else if (pushed == 2)
	{
		if ((*(s.stack_a))->content > (*(s.stack_a))->next->content)
		{
			sa(s.stack_a);
			if (bench)
				(*stats)->sa_count++;
		}
	}
}

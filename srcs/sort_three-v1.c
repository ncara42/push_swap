/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three-v1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:58:54 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/11 04:35:59 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	update_st(t_stats **stats, int sa, int pb, int pa)
{
	if (!stats || !*stats)
		return ;
	(*stats)->sa_count += sa;
	(*stats)->pb_count += pb;
	(*stats)->pa_count += pa;
}

void	sort_three_top_next_next(t_stacks s, t_stats **st, t_fst *f, int b)
{
	if (f->first < f->second && f->second > f->third && f->first < f->third)
	{
		pb(s.stack_a, s.stack_b);
		sa(s.stack_a);
		pa(s.stack_a, s.stack_b);
		if (b)
			update_st(st, 1, 1, 1);
	}
	else if (f->first > f->second && f->second > f->third)
	{
		sa(s.stack_a);
		pb(s.stack_a, s.stack_b);
		sa(s.stack_a);
		pa(s.stack_a, s.stack_b);
		sa(s.stack_a);
		if (b)
			update_st(st, 3, 1, 1);
	}
}

void	sort_three_top_next(t_stacks s, t_stats **stats, t_fst *fst, int bench)
{
	if (fst->first > fst->second && fst->second < fst->third
		&& fst->first < fst->third)
	{
		sa(s.stack_a);
		if (bench)
			update_st(stats, 1, 0, 0);
	}
	else if (fst->first > fst->second && fst->second < fst->third
		&& fst->first > fst->third)
	{
		sa(s.stack_a);
		pb(s.stack_a, s.stack_b);
		sa(s.stack_a);
		pa(s.stack_a, s.stack_b);
		if (bench)
			update_st(stats, 2, 1, 1);
	}
}

void	sort_three_top(t_stacks s, t_stats **stats, t_fst *fst, int bench)
{
	fst->first = (*(s.stack_a))->content;
	fst->second = (*(s.stack_a))->next->content;
	fst->third = (*(s.stack_a))->next->next->content;
	sort_three_top_next(s, stats, fst, bench);
	sort_three_top_next_next(s, stats, fst, bench);
	if (fst->first < fst->second && fst->second > fst->third
		&& fst->first > fst->third)
	{
		pb(s.stack_a, s.stack_b);
		sa(s.stack_a);
		pa(s.stack_a, s.stack_b);
		sa(s.stack_a);
		if (bench)
			update_st(stats, 2, 1, 1);
	}
}

void	sort_three(t_stacks s, int pushed, t_stats **stats)
{
	t_fst	fst;
	int		bench;

	bench = 0;
	if (stats && *stats)
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
				update_st(stats, 1, 0, 0);
		}
	}
}

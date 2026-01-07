/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three-v1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:58:54 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/07 22:12:42 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_top(t_stacks s, t_stats **stats)
{
	sort_three_top_next(s, stats);
	sort_three_top_next_next(s, stats);
}

void	sort_three_top_next(t_stacks s, t_stats **stats)
{
	long	first;
	long	second;
	long	third;

	first = (*(s.stack_a))->content;
	second = (*(s.stack_a))->next->content;
	third = (*(s.stack_a))->next->next->content;
	if (first > second && second < third && first < third)
	{
		if ((*stats)->isbench)
		{
			sa(s.stack_a, 1);
			(*stats)->sa_count++;
		}
		else
			sa(s.stack_a, 0);
	}
	else if (first > second && second < third && first > third)
	{
		if ((*stats)->isbench)
		{
			sa(s.stack_a, 1);
			pb(s.stack_a, s.stack_b, 1);
			sa(s.stack_a, 1);
			pa(s.stack_a, s.stack_b, 1);
			(*stats)->sa_count += 2;
			(*stats)->pb_count++;
			(*stats)->pa_count++;
		}
		else
		{
			sa(s.stack_a, 0);
			pb(s.stack_a, s.stack_b, 0);
			sa(s.stack_a, 0);
			pa(s.stack_a, s.stack_b, 0);
		}
	}
	else if (first < second && second > third && first > third)
	{
		if ((*stats)->isbench)
		{
			pb(s.stack_a, s.stack_b, 1);
			sa(s.stack_a, 1);
			pa(s.stack_a, s.stack_b, 1);
			sa(s.stack_a, 1);
			(*stats)->pb_count++;
			(*stats)->sa_count += 2;
			(*stats)->pa_count++;
		}
		else
		{
			pb(s.stack_a, s.stack_b, 0);
			sa(s.stack_a, 0);
			pa(s.stack_a, s.stack_b, 0);
			sa(s.stack_a, 0);
		}
	}
}

void	sort_three_top_next_next(t_stacks s, t_stats **stats)
{
	long	first;
	long	second;
	long	third;

	first = (*(s.stack_a))->content;
	second = (*s.stack_a)->next->content;
	third = (*s.stack_a)->next->next->content;
	if (first < second && second > third && first < third)
	{
		if ((*stats)->isbench)
		{
			pb(s.stack_a, s.stack_b, 1);
			sa(s.stack_a, 1);
			pa(s.stack_a, s.stack_b, 1);
			(*stats)->pb_count++;
			(*stats)->sa_count++;
			(*stats)->pa_count++;
		}
		else
		{
			pb(s.stack_a, s.stack_b, 0);
			sa(s.stack_a, 0);
			pa(s.stack_a, s.stack_b, 0);
		}
	}
	else if (first > second && second > third)
	{
		if ((*stats)->isbench)
		{
			sa(s.stack_a, 1);
			pb(s.stack_a, s.stack_b, 1);
			sa(s.stack_a, 1);
			pa(s.stack_a, s.stack_b, 1);
			sa(s.stack_a, 1);
			(*stats)->sa_count += 3;
			(*stats)->pb_count++;
			(*stats)->pa_count++;
		}
		else
		{
			sa(s.stack_a, 0);
			pb(s.stack_a, s.stack_b, 0);
			sa(s.stack_a, 0);
			pa(s.stack_a, s.stack_b, 0);
			sa(s.stack_a, 0);
		}
	}
}

void	sort_three(t_stacks s, int pushed, t_stats **stats)
{
	int	bench;

	if (!*stats || !stats)
		bench = 0;
	else
		bench = (*stats)->isbench;
	if (pushed == 3 && ft_lstsize(*(s.stack_a)) == 3)
		sort_three_a(s.stack_a, stats);
	else if (pushed == 3)
		sort_three_top(s, stats);
	else if (pushed == 2)
	{
		if ((*(s.stack_a))->content > (*(s.stack_a))->next->content)
		{
			if ((*stats)->isbench)
			{
				sa(s.stack_a, 1);
				(*stats)->sa_count++;
			}
			else
				sa(s.stack_a, 0);
		}
	}
}

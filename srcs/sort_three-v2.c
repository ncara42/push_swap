/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three-v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:24:03 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/07 23:44:32 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_a(t_list **stack_a, t_stats **stats)
{
	long	first;
	long	second;
	long	third;
	int		bench;

	if (!stats || !*stats)
		bench = 0;
	else
		bench = (*stats)->isbench;
	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if (first > second && second < third && first < third)
	{
		if (bench)
		{
			sa(stack_a, 1);
			(*stats)->sa_count++;
		}
		else
			sa(stack_a, 0);
	}
	else if (first > second && second > third)
	{
		if (bench)
		{
			sa(stack_a, 1);
			rra(stack_a, 1);
			(*stats)->sa_count++;
			(*stats)->rra_count++;
		}
		else
		{
			sa(stack_a, 0);
			rra(stack_a, 0);
		}
	}
	else if (first > second && second < third && first > third)
	{
		if (bench)
		{
			ra(stack_a, 1);
			(*stats)->ra_count++;
		}
		else
			ra(stack_a, 0);
	}
	else if (first < second && second > third && first < third)
	{
		if (bench)
		{
			sa(stack_a, 1);
			ra(stack_a, 1);
			(*stats)->sa_count++;
			(*stats)->ra_count++;
		}
		else
		{
			sa(stack_a, 0);
			ra(stack_a, 0);
		}
	}
	else if (first < second && second > third && first > third)
	{
		if (bench)
		{
			rra(stack_a, 1);
			(*stats)->rra_count++;
		}
		else
			rra(stack_a, 0);
	}
}

void	sort_three_b(t_stacks s, int len, t_stats **stats)
{
	int	bench;

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
		sort_three_top(s, stats);
	}
}

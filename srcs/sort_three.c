/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:58:54 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/06 11:01:55 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_top(t_list **stack, t_list **stack2, int bench, t_stats **s)
{
	sort_three_top_next(stack, stack2, bench, s);
	sort_three_top_next_next(stack, stack2, bench, s);
}

void	sort_three_top_next(t_list **stack, t_list **stack2,
			int bench, t_stats **stats)
{
	long	first;
	long	second;
	long	third;

	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (first > second && second < third && first < third)
	{
		if (bench)
		{
			sa(stack, 1);
			(*stats)->sa_count++;
		}
		else
			sa(stack, 0);
	}
	else if (first > second && second < third && first > third)
	{
		if (bench)
		{
			sa(stack, 1);
			pb(stack, stack2, 1);
			sa(stack, 1);
			pa(stack, stack2, 1);
			(*stats)->sa_count += 2;
			(*stats)->pb_count++;
			(*stats)->pa_count++;
		}
		else
		{
			sa(stack, 0);
			pb(stack, stack2, 0);
			sa(stack, 0);
			pa(stack, stack2, 0);
		}
	}
	else if (first < second && second > third && first > third)
	{
		if (bench)
		{
			pb(stack, stack2, 1);
			sa(stack, 1);
			pa(stack, stack2, 1);
			sa(stack, 1);
			(*stats)->pb_count++;
			(*stats)->sa_count += 2;
			(*stats)->pa_count++;
		}
		else
		{
			pb(stack, stack2, 0);
			sa(stack, 0);
			pa(stack, stack2, 0);
			sa(stack, 0);
		}
	}
}

void	sort_three_top_next_next(t_list **stack, t_list **stack2,
			int bench, t_stats **stats)
{
	long	first;
	long	second;
	long	third;

	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (first < second && second > third && first < third)
	{
		if (bench)
		{
			pb(stack, stack2, 1);
			sa(stack, 1);
			pa(stack, stack2, 1);
			(*stats)->pb_count++;
			(*stats)->sa_count++;
			(*stats)->pa_count++;
		}
		else
		{
			pb(stack, stack2, 0);
			sa(stack, 0);
			pa(stack, stack2, 0);
		}
	}
	else if (first > second && second > third)
	{
		if (bench)
		{
			sa(stack, 1);
			pb(stack, stack2, 1);
			sa(stack, 1);
			pa(stack, stack2, 1);
			sa(stack, 1);
			(*stats)->sa_count += 3;
			(*stats)->pb_count++;
			(*stats)->pa_count++;
		}
		else
		{
			sa(stack, 0);
			pb(stack, stack2, 0);
			sa(stack, 0);
			pa(stack, stack2, 0);
			sa(stack, 0);
		}
	}
}

void	sort_three(t_list **stack, t_list **stack2, int pushed,
		int bench, t_stats **stats)
{
	if (pushed == 3 && ft_lstsize(*stack) == 3)
		sort_three_a(stack, bench, stats);
	else if (pushed == 3)
		sort_three_top(stack, stack2, bench, stats);
	else if (pushed == 2)
	{
		if ((*stack)->content > (*stack)->next->content)
		{
			if (bench)
			{
				sa(stack, 1);
				(*stats)->sa_count++;
			}
			else
				sa(stack, 0);
		}
	}
}

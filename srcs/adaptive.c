/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 01:41:56 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/07 20:33:52 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	which_algo(t_optype opt, t_list **stack_a, t_list **stack_b,
			t_stats **stats)
{
	if (opt == UNKNOWN)
	{
		if ((*stats)->di < 0.2)
			opt = SIMPLE;
		else if ((*stats)->di < 0.5)
			opt = MEDIUM;
		else if ((*stats)->di >= 0.5)
			opt = COMPLEX;
	}
	if (opt == SIMPLE)
	{
		if (bench)
			bench_simple(stack_a, stack_b, stats);
		else
			simple(stack_a, stack_b);
	}
	else if (opt == MEDIUM)
	{
		medium(stack_a, stack_b);
	}
	else if (opt == COMPLEX)
	{
		if (bench)
			bench_complex(stack_a, stack_b, stats, 1);
		else
			complex(stack_a, stack_b);
	}
	return ;
}

void	adaptive(t_list **stack_a, t_list **stack_b,
						t_options **options)
{
	int			bench;
	t_optype	choosenoption;
	float		d;
	t_stats		*stats;

	stats = malloc(sizeof(t_stats));
	if (!stats)
		return ;
	ft_bzero(stats, sizeof(t_stats));
	stats->sizea = ft_lstsize(*stack_a);
	stats->di = disorder_index(stats->sizea, *stack_a);
	choosenoption = UNKNOWN;
	if (!d)
		return ;
	if (*options)
	{
		if ((*options)->count == 2)
		{
			stats->isbench = 1;
			if ((*options)->options[0] != BENCH)
				choosenoption = (*options)->options[0];
			else
				choosenoption = (*options)->options[1];
		}
		else
		{
			if ((*options)->options[0] == BENCH)
			{
				stats->isbench = 1;
				stats->isadaptive = 1;
			}
			else
				choosenoption = (*options)->options[0];
		}
	}
	else
		stats->isadaptive = 1;
	which_algo(choosenoption, stack_a, stack_b, &stats);
}

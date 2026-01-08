/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 01:41:56 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/08 17:41:42 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	which_algo(t_optype opt, t_stacks s, t_stats **stats)
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
		if ((*stats)->isbench)
			bench_simple(s, stats);
		else
			simple(s.stack_a, s.stack_b);
	}
	else if (opt == MEDIUM)
	{
		if ((*stats)->isbench)
			bench_medium(s, stats);
		else
			medium(s);
	}
	else if (opt == COMPLEX)
	{
		if ((*stats)->isbench)
			bench_complex(s, stats, ft_lstsize(*s.stack_a), 1);
		else
			complex(s, ft_lstsize(*s.stack_a));
	}
	return ;
}

void	adaptive(t_stacks s, t_options **options)
{
	t_optype	choosenoption;
	t_stats		*stats;

	choosenoption = UNKNOWN;
	stats = malloc(sizeof(t_stats));
	if (!stats)
		return ;
	ft_bzero(stats, sizeof(t_stats));
	stats->sizea = ft_lstsize(*s.stack_a);
	stats->di = disorder_index(stats->sizea, *s.stack_a);
	if (!stats->di)
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
	which_algo(choosenoption, s, &stats);
}

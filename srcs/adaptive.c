/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:12:07 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/12 19:26:38 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	run_simple(t_stacks s, t_stats **stats)
{
	if ((*stats)->isbench)
		bench_simple(s, stats);
	else
		simple(s.stack_a, s.stack_b);
}

static void	run_medium(t_stacks s, t_stats **stats)
{
	if ((*stats)->isbench)
		bench_medium(s, stats);
	else
		medium(s);
}

static void	run_complex(t_stacks s, t_stats **stats)
{
	int	size;

	size = ft_lstsize(*s.stack_a);
	if ((*stats)->isbench)
		bench_complex(s, stats, size, 1);
	else
		complex(s, size);
}

void	which_algo(t_optype opt, t_stacks s, t_stats **stats)
{
	if (opt == UNKNOWN || opt == ADAPTIVE)
	{
		(*stats)->isadaptive = 1;
		if ((*stats)->di == 0)
			opt = UNKNOWN;
		else if ((*stats)->di < 20)
			opt = SIMPLE;
		else if ((*stats)->di < 50)
			opt = MEDIUM;
		else if ((*stats)->di >= 50)
			opt = COMPLEX;
	}
	if (opt == SIMPLE)
		run_simple(s, stats);
	else if (opt == MEDIUM)
		run_medium(s, stats);
	else if (opt == COMPLEX)
		run_complex(s, stats);
	else
	{
		if ((*stats)->isbench)
			print_bench_info(stats, SIMPLE);
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
	if (*options)
		select_option(&choosenoption, stats, *options);
	else
		stats->isadaptive = 1;
	which_algo(choosenoption, s, &stats);
	free(stats);
}

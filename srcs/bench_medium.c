/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:11:20 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/05 22:32:19 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	gettotalcount(t_stats **stats)
{
	size_t	total;

	total = ((*stats)->ra_count + (*stats)->rb_count + (*stats)->rr_count +
			(*stats)->rra_count + (*stats)->rrb_count + (*stats)->rrr_count +
			(*stats)->pa_count + (*stats)->pb_count + (*stats)->sa_count +
			(*stats)->sb_count + (*stats)->ss_count);
	(*stats)->total_count = total;
}

void	bench_medium(t_list **stack_a, t_list **stack_b, float d, int adapt)
{
	long		*tmparr;
	t_chunks	*chunksmx;
	t_stats		*stats;

	if (!stack_a || !*stack_a)
		return ;
	stats = malloc(sizeof(t_stats));
	if (!stats)
		return ;
	ft_bzero(stats, sizeof(t_stats));
	tmparr = getsortedarr(*stack_a, ft_lstsize(*stack_a));
	chunksmx = divideinchunks(*stack_a);
	if (!chunksmx)
		return ;
	domediummoves(stack_a, stack_b, &chunksmx, 1, &stats);
	freechunks(chunksmx);
	free(tmparr);
	if (adapt)
		stats->algo = ADAPTIVE;
	else
		stats->algo = MEDIUM;
	gettotalcount(&stats);
	printbenchinfo(&stats, d, MEDIUM);
}

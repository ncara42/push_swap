/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:32:15 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/07 19:40:08 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	count_bench(t_stats **stats)
{
	size_t	total;

	total = ((*stats)->ra_count + (*stats)->rb_count + (*stats)->rra_count
			+ (*stats)->rra_count + (*stats)->rrb_count + (*stats)->rrr_count
			+ (*stats)->pa_count + (*stats)->pb_count + (*stats)->sa_count
			+ (*stats)->sb_count + (*stats)->ss_count);
	(*stats)->total_count = total;
}

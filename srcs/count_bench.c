/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_totalcount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:32:15 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/06 23:55:32 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	count_bench(t_stats **stats)
{
	size_t	total;

	total = ((*stats)->ra_count + (*stats)->rb_count + (*stats)->rr_count +
			(*stats)->rra_count + (*stats)->rrb_count + (*stats)->rrr_count +
			(*stats)->pa_count + (*stats)->pb_count + (*stats)->sa_count +
			(*stats)->sb_count + (*stats)->ss_count);
	(*stats)->total_count = total;
}
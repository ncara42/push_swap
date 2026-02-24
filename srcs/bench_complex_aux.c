/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_complex_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 01:42:01 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/11 04:55:32 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	restore_b_stack(t_list **stack_b, int rb_count, t_stats **stats)
{
	while (rb_count-- > 0)
	{
		rrb(stack_b);
		(*stats)->rrb_count++;
	}
}

void	restore_a_stack(t_list **stack_a, int ra_count, t_stats **stats)
{
	while (ra_count-- > 0)
	{
		rra(stack_a);
		(*stats)->rra_count++;
	}
}

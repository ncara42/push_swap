/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbenchinfo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:59:06 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/06 14:17:57 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printbenchinfo(t_stats **stats, float d, t_optype opt)
{
	int percent = d * 100;
	ft_printf("[bench] disorder:     %i %%\n", percent);
	if ((*stats)->algo == SIMPLE)
		ft_printf("[bench] strategy:     Simple / O(nˆ2)\n");
	else if ((*stats)->algo == MEDIUM)
		ft_printf("[bench] strategy:     Medium / O(n√n)\n");
	else if ((*stats)->algo == COMPLEX)
		ft_printf("[bench] strategy:     Complex / O(n log n)\n");
	else if ((*stats)->algo == ADAPTIVE)
	{
		ft_printf("[bench] strategy:     Adaptive / ");
		if (opt == SIMPLE)
			ft_printf("O(nˆ2)\n");
		else if (opt == MEDIUM)
			ft_printf("O(n√n)\n");
		else if (opt == COMPLEX)
			ft_printf("O(n log n)\n");
		else
			ft_printf("OOPS\n");
	}
	else
		ft_printf("OOPS\n");
	ft_printf("[bench] total_ops:    %d\n", (*stats)->total_count);
	ft_printf("[bench] sa:  %d  sb:  %d  ss:  %d  pa:  %d  pb:  %d\n",
			(*stats)->sa_count, (*stats)->sb_count, (*stats)->ss_count,
			(*stats)->pa_count, (*stats)->pb_count);
	ft_printf("[bench] ra:  %d  rb:  %d  rr:  %d  rra:  %d rrb:  %d  rrr:  %d\n",
			(*stats)->ra_count, (*stats)->rb_count, (*stats)->rr_count,
			(*stats)->rra_count, (*stats)->rrb_count, (*stats)->rrr_count);

}

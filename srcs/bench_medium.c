/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:28:36 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/12 19:05:07 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bench_medium(t_stacks s, t_stats **stats)
{
	long	*arr;
	int		size;

	size = ft_lstsize(*s.stack_a);
	if (size == 1)
	{
		print_bench_info(stats, MEDIUM);
		return ;
	}
	if (disorder_index(size, *s.stack_a) == 0)
		return (print_bench_info(stats, MEDIUM));
	arr = array_sort(*s.stack_a, size);
	if (!arr)
		return ;
	bench_medium_get_chunks(s, arr, 1, stats);
	bench_medium_pushing_to_a(s, 1, stats);
	free(arr);
	if ((*stats)->isadaptive)
		(*stats)->algo = ADAPTIVE;
	else
		(*stats)->algo = MEDIUM;
	count_bench(stats);
	print_bench_info(stats, MEDIUM);
}

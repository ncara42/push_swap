/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbenchinfo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-ach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:59:06 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/05 20:25:55 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printbenchinfo(t_stats **stats, float d, t_optype opt)
{
	write(1, "[bench] disorder:     ", 22);
	ft_putnbr(d * 100);
	write(1, "%\n", 2);
	write(1, "[bench] strategy:     ", 22);
	if ((*stats)->algo == SIMPLE)
		write(1, "Simple / O(nˆ2)\n", 17);
	else if ((*stats)->algo == MEDIUM)
		write(1, "Medium / O(n√n)\n", 18);
	else if ((*stats)->algo == COMPLEX)
		write(1, "Complex / O(n log n)\n", 21);
	else if ((*stats)->algo == ADAPTIVE)
	{
		write(1, "Adaptive / ", 11);
		if (opt == SIMPLE)
			write(1, "O(nˆ2)\n", 8);
		else if (opt == MEDIUM)
			write(1, "O(n√n)\n", 9);
		else if (opt == COMPLEX)
			write(1, "O(n log n)\n", 11);
		else
			write(1, "OOPS\n", 5);
	}
	else
		write(1, "BOUM\n", 5);
	write(1, "[bench] total_ops:    ", 22);
	ft_putnbr((*stats)->total_count);
	write(1, "\n", 1);
	write(1, "[bench] ", 8);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbenchinfo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:59:06 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/06 07:59:05 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printbenchinfo(t_stats **stats, float d, t_optype opt)
{
	ft_printf("%s", "[bench] disorder:     ");
	ft_putnbr(d * 100);
    ft_printf("%");
	ft_printf("\n");
	ft_printf("%s", "[bench] strategy:     ");
	if ((*stats)->algo == SIMPLE)
		ft_printf("%s", "Simple / O(nˆ2)\n");
	else if ((*stats)->algo == MEDIUM)
		ft_printf("%s", "Medium / O(n√n)\n");
	else if ((*stats)->algo == COMPLEX)
		ft_printf("%s", "Complex / O(n log n)\n");
	else if ((*stats)->algo == ADAPTIVE)
	{
		ft_printf("%s", "Adaptive / ");
		if (opt == SIMPLE)
			ft_printf("%s", "O(nˆ2)\n");
		else if (opt == MEDIUM)
			ft_printf("%s", "O(n√n)\n");
		else if (opt == COMPLEX)
			ft_printf("%s", "O(n log n)\n");
		else
			ft_printf("%s", "OOPS\n");
	}
	else
		ft_printf("%s", "OOPS\n");
	ft_printf("%s", "[bench] total_ops:    ");
	ft_putnbr((*stats)->total_count);
	ft_printf("\n");
	ft_printf("%s\n", "Seguir...");

}

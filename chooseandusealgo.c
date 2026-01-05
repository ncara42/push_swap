/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chooseandusealgo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 01:41:56 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/05 19:28:33 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculateandusedisorderalgo(float d, t_list **a, t_list **b, int bench)
{
	if (d < 0.2)
		whichalgo(SIMPLE, bench, a, b, 1);
	else if (d >= 0.2 && d < 0.5)
		whichalgo(MEDIUM, bench, a, b, 1);
	else if (d >= 0.5)
		whichalgo(COMPLEX, bench, a, b, 1);
	return ;
}

void	whichalgo(t_optype opt, int bench, t_list **a, t_list **b, int adapt)
{
	float d;

	d = index_error(ft_lstsize(*a), *a);
	if (opt == SIMPLE)
	{
		if (bench)
			bench_simple(a, b, d, adapt);
		else
			simple(a, b);
	}
	else if (opt == MEDIUM)
	{
		if (bench)
			bench_medium(a, b, d, adapt);
		else
			medium(a, b);
	}
	else if (opt == COMPLEX)
	{
		/*
		if (bench)
			bench_complex(a, b, ft_lstsize(*a), d, adapt);
		else
			complex(a, b, ft_lstsize(*a));
			*/
		write(1, "Noel gay", 8);
	}
	else
		calculateandusedisorderalgo(d, a, b, bench);
	return ;
}

void	chooseandusealgo(t_list **stack_a, t_list **stack_b,
						t_options **options)
{
	int				bench;
	t_optype	choosenoption;

	bench = 0;
	choosenoption = UNKNOWN;
	if (*options)
	{
		if ((*options)->count == 2)
		{
			bench = 1;
			if ((*options)->options[0] != BENCH)
				choosenoption = (*options)->options[0];
			else
				choosenoption = (*options)->options[1];
		}
		else
		{
			if ((*options)->options[0] == BENCH)
				bench = 1;
			else
				choosenoption = (*options)->options[0];
		}
	}
	whichalgo(choosenoption, bench, stack_a, stack_b, 0);
}

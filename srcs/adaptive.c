/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 01:41:56 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/07 00:21:12 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	which_algo(t_optype opt, int bench, t_list **stack_a, t_list **stack_b,
			int adapt)
{
	float	d;

	d = disorder_index(ft_lstsize(*stack_a), *stack_a);
	if (opt == UNKNOWN)
	{
		if (d < 0.2)
			opt = SIMPLE;
		else if (d < 0.5)
			opt = MEDIUM;
		else if (d >= 0.5)
			opt = COMPLEX;
	}
	if (opt == SIMPLE)
	{
		if (bench)
			bench_simple(stack_a, stack_b, d, adapt);
		else
			simple(stack_a, stack_b); 
	}
	else if (opt == MEDIUM)
	{
		medium(stack_a, stack_b);
	}
	else if (opt == COMPLEX)
	{
		if (bench)
			bench_complex(stack_a, stack_b, ft_lstsize(*stack_a), d, NULL, adapt, 1);
		else
			complex(stack_a, stack_b, ft_lstsize(*stack_a));
	}
	return ;
}

void	adaptive(t_list **stack_a, t_list **stack_b,
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
	which_algo(choosenoption, bench, stack_a, stack_b, bench);
}

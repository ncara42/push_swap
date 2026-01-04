/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chooseandusealgo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-ach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 01:41:56 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/04 01:55:47 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	usealgo(enum e_options option, t_list **stack_a, t_list **stack_b)
{
	switch (option)
		case SIMPLE:
			simple(stack_a, stack_b);
		case MEDIUM:
			medium(stack_a, stack_b);
		case COMPLEX:
			complex(stack_a, stack_b);
}

int	chooseandusealgo(t_list **stack_a, t_list **stack_b, t_options **options)
{
	size_t			i;
	int				bench;
	enum e_options	choosenoption;

	i = 0;
	bench = 0;
	if (*options)
	{
		if ((*options)->count == 2)
		{
			bench = 1;
			if ((*options)->options[0] != BENCH)
				choosenoption = (*options)->options[0];
			else if ((*options)->options[1] != BENCH)
				choosenoption = (*options)->options[1];
		}
		else
			choosenoption = (*options)->options[0];
		if (bench && choosenoption)
			bench(stack_a, choosenoption);
		else if (bench && !choosenoption)
			bench(stack_a, 0);
	}
	else

}

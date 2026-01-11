/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:16:56 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/11 19:38:00 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	complex(t_stacks s, int len)
{
	long	pivot;
	long	*arr;
	int		pushed;

	if (disorder_index(ft_lstsize(*s.stack_a), *s.stack_a) == 0)
		return ;
	if (len <= 3)
	{
		sort_three(s, len, 0);
		return ;
	}
	arr = array_sort(*(s.stack_a), len);
	if (!arr)
		return ;
	pivot = arr[len / 2];
	free(arr);
	pushed = complex_a_next(s, len, pivot);
	complex(s, len - pushed);
	complex_b(s, pushed);
}

int	complex_a_next(t_stacks s, int len, long pivot)
{
	int		i;
	int		pushed;
	int		ra_count;

	i = 0;
	pushed = 0;
	ra_count = 0;
	while (i < len && *(s.stack_a))
	{
		if ((*(s.stack_a))->content <= pivot)
		{
			pb(s.stack_a, s.stack_b);
			pushed++;
		}
		else if ((*(s.stack_a))->content > pivot)
		{
			ra(s.stack_a);
			ra_count++;
		}
		i++;
	}
	while (ra_count-- > 0)
		rra(s.stack_a);
	return (pushed);
}

void	complex_b(t_stacks s, int len)
{
	long	pivot;
	long	*arr;
	int		pushed;

	pushed = 0;
	if (len <= 3)
	{
		sort_three_b(s, len, 0);
		return ;
	}
	arr = array_sort(*(s.stack_b), len);
	if (!arr)
		return ;
	pivot = arr[len / 2];
	free(arr);
	pushed = complex_b_next(s, len, pivot);
	complex(s, pushed);
	complex_b(s, len - pushed);
}

int	complex_b_next(t_stacks s, int len, long pivot)
{
	int	i;
	int	pushed;
	int	rb_count;

	i = 0;
	rb_count = 0;
	pushed = 0;
	while (i < len && *(s.stack_b))
	{
		if ((*(s.stack_b))->content >= pivot)
		{
			pa(s.stack_a, s.stack_b);
			pushed++;
		}
		else if ((*(s.stack_b))->content < pivot)
		{
			rb(s.stack_b);
			rb_count++;
		}
		i++;
	}
	while (rb_count-- > 0)
		rrb(s.stack_b);
	return (pushed);
}

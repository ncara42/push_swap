/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:32:15 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/06 13:08:51 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static ssize_t	getindex(long chunkvalue, t_list *stack_a)
{
	size_t	index;

	index = 0;
	while (stack_a)
	{
		if (stack_a->content == chunkvalue)
			return (index);
		stack_a = stack_a->next;
		index++;
	}
	return (-1);
}

void	moveandpushb(t_list **stack_a, t_list **stack_b, size_t index,
			int bench, t_stats **stats)
{
	size_t	size;
	size_t	i;

	size = ft_lstsize(*stack_a);
	i = 0;
	if (index <= size / 2)
		while (i++ < index)
		{
			if (bench)
			{
				ra(stack_a, 1);
				(*stats)->ra_count++;
			}
			else
				ra(stack_a, 0);
		}
	else
		while (i++ < size - index)
		{
			if (bench)
			{
				rra(stack_a, 1);
				(*stats)->rra_count++;
			}
			else
				rra(stack_a, 0);
		}
	if (bench)
	{
		pb(stack_a, stack_b, 1);
		(*stats)->pb_count++;
	}
	else
		pb(stack_a, stack_b, 0);
}

void	domediummoves(t_list **stack_a, t_list **stack_b, t_chunks **chunks,
			int bench, t_stats **stats)
{
	size_t	i;
	size_t	j;
	size_t	index;

	i = 0;
	while (i < (*chunks)->count)
	{
		j = 0;
		while (j < (*chunks)->sizes[i])
		{
			if (ft_lstsize(*stack_a) > 3)
			{
				index = getindex((*chunks)->chunks[i][j], *stack_a);
				moveandpushb(stack_a, stack_b, index, bench, stats);
			}
			j++;
		}
		i++;
	}
	if (ft_lstsize(*stack_a) >= 3)
		sort_three_a(stack_a, bench, stats);
	while (*stack_b)
	{
		if (bench)
		{
			pa(stack_a, stack_b, 1);
			(*stats)->pa_count++;
		}
		else
			pa(stack_a, stack_b, 0);
	}
}

void	medium(t_list **stack_a, t_list **stack_b)
{
	long		*tmparr;
	t_chunks	*chunksmx;

	if (!stack_a || !*stack_a)
		return ;
	tmparr = getsortedarr(*stack_a, ft_lstsize(*stack_a));
	chunksmx = divideinchunks(*stack_a);
	if (!chunksmx)
		return ;
	domediummoves(stack_a, stack_b, &chunksmx, 0, NULL);
	freechunks(chunksmx);
	free(tmparr);
}

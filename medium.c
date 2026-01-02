/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:32:15 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/02 16:44:00 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	moveandpushb(t_list **stack_a, t_list **stack_b, size_t index)
{
	size_t	size;
	size_t	i;

	size = ft_lstsize(*stack_a);
	i = 0;
	if (index <= size / 2)
		while (i++ < index)
			ra(stack_a);
	else
		while (i++ < size - index)
			rra(stack_a);
	pb(stack_a, stack_b);
}

void	medium(t_list **stack_a, t_list **stack_b)
{
	size_t		size;
	size_t		i;
	size_t		j;
	long		*tmparr;
	t_chunks	*chunksmx;

	if (!stack_a || !*stack_a)
		return ;
	size = ft_lstsize(*stack_a);
	tmparr = getsortedarr(*stack_a, ft_lstsize(*stack_a));
	chunksmx = divideinchunks(*stack_a);
	if (!chunksmx)
		return ;
	i = 0;
	while (i < chunksmx->count)
	{
		j = 0;
		while (j < chunksmx->sizes[i])
		{
			if (ft_lstsize(*stack_a) > 3)
				moveandpushb(stack_a, stack_b, getindex(chunksmx->chunks[i][j], *stack_a));
			j++;
		}
		i++;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
	freechunks(chunksmx);
	free(tmparr);
}

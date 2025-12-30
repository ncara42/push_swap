/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:32:15 by vvan-ach          #+#    #+#             */
/*   Updated: 2025/12/30 22:50:44 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubblesort(long	*arr, size_t size)
{
	size_t	i;
	size_t	j;
	long	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static long	*getsortedarr(t_list *stack)
{
	long	*arr;
	size_t	i;
	size_t	size;

	size = ft_lstsize(stack);
	arr = malloc(size * sizeof(long));
	if (!arr)
		return (NULL);
	i = 0;
	while (stack)
	{
		arr[i] = stack->content;
		stack = stack->next;
		i++;
	}
	bubblesort(arr, size);
	return (arr);
}

t_chunks	*divideinchunks(long *tmparr, size_t size)
{
	t_chunks	*res;
	size_t	rest;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	chunkamount;

	chunkamount = (size_t)int_sqrt(size);
	rest = size % chunkamount;
		res = malloc(sizeof(t_chunks));
	if (!res)
		return (NULL);
	if (rest)
		res->count = chunkamount + 1;
	else
		res->count = chunkamount;
	res->chunks = malloc(res->count * sizeof(long *));
	res->sizes = malloc(res->count * sizeof(size_t));
	if (!res->chunks || !res->sizes)
		return (NULL);
	i = 0;
	j = 0;
	while (i < chunkamount)
	{
		res->sizes[i] = chunkamount;
		res->chunks[i] = malloc(chunkamount * sizeof(long));
		k = 0;
		while (k < chunkamount)
			res->chunks[i][k++] = tmparr[j++];
		i++;
	}
	if (rest)
	{
		k = 0;
		res->sizes[i] = rest;
		res->chunks[i] = malloc(rest * sizeof(long));
		while (k < rest)
			res->chunks[i][k++] = tmparr[j++];
	}
	return (res);
}

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

void	freechunks(t_chunks *chunks)
{
	size_t	i;
	if (!chunks)
		return ;

	i = 0;
	while (i < chunks->count)
		free(chunks->chunks[i++]);
	free(chunks->chunks);
	free(chunks->sizes);
	free(chunks);
}

void	medium(t_list **stack_a, t_list **stack_b)
{
	size_t	size;
	size_t	i;
	size_t	j;
	long	*tmparr;
	t_chunks	*chunksmx;

	if (!stack_a || !*stack_a)
		return ;
	size = ft_lstsize(*stack_a);
	tmparr = getsortedarr(*stack_a);
	chunksmx = divideinchunks(tmparr, size);
	if (!chunksmx)
		return ;
	i = 0;
	while (i < chunksmx->count)
	{
		j = 0;
		while (j < chunksmx->sizes[i])
		{
			if (ft_lstsize(*stack_a) > 3)
				moveandpushb(stack_a, stack_b, getindex(chunksmx->chunks[i][j++], *stack_a));
			else
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

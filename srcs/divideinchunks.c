/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divideinchunks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:42:03 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/05 22:32:34 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	*getsortedarr(t_list *stack, int len)
{
	long	*arr;
	int		i;

	arr = malloc(len * sizeof(long));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len && stack)
	{
		arr[i] = stack->content;
		stack = stack->next;
		i++;
	}
	bubblesort(arr, len);
	return (arr);
}

void	fillchunks(t_chunks **res, size_t amount, long *tmparr, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (i < amount)
	{
		(*res)->sizes[i] = amount;
		(*res)->chunks[i] = malloc(amount * sizeof(long));
		k = 0;
		while (k < amount)
			(*res)->chunks[i][k++] = tmparr[j++];
		i++;
	}
	if (size % amount)
	{
		k = 0;
		(*res)->sizes[i] = size % amount;
		(*res)->chunks[i] = malloc((size % amount) * sizeof(long));
		while (k < (size % amount))
			(*res)->chunks[i][k++] = tmparr[j++];
	}
}

t_chunks	*divideinchunks(t_list *stack_a)
{
	t_chunks	*res;
	size_t		chunkamount;
	long		*tmparr;
	size_t		size;

	size = ft_lstsize(stack_a);
	tmparr = getsortedarr(stack_a, size);
	chunkamount = (size_t)int_sqrt(size);
	res = malloc(sizeof(t_chunks));
	if (!res)
		return (NULL);
	res->count = chunkamount;
	if (size % chunkamount)
		res->count++;
	res->chunks = malloc(res->count * sizeof(long *));
	res->sizes = malloc(res->count * sizeof(size_t));
	if (!res->chunks || !res->sizes)
		return (NULL);
	fillchunks(&res, chunkamount, tmparr, size);
	free(tmparr);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divideinchunks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:42:03 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/06 19:55:49 by admin            ###   ########.fr       */
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
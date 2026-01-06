/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:42:03 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/06 23:52:01 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	*array_sort(t_list *stack, int len)
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 16:59:18 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/10 16:59:18 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_n_chunks(int n)
{
	if (n <= 5)
		return (1);
	else if (n <= 50)
		return (2);
	else if (n <= 100)
		return (6);
	else if (n <= 500)
		return (9);
	return (11);
}

int	get_top_pos(t_list *stack_a, long *arr, int start, int end)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->content >= arr[start] && stack_a->content <= arr[end])
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (-1);
}

int	get_bottom_pos(t_list *stack_a, long *arr, int start, int end)
{
	int	i;
	int	bottom;

	i = 0;
	bottom = -1;
	while (stack_a)
	{
		if (stack_a->content >= arr[start] && stack_a->content <= arr[end])
			bottom = i;
		stack_a = stack_a->next;
		i++;
	}
	return (bottom);
}

void	get_chunks(t_stacks s, long *arr)
{
	int	chunks;
	int	total_size;
	int	size;
	int	i;

	total_size = ft_lstsize(*s.stack_a);
	chunks = get_n_chunks(total_size);
	size = total_size / chunks;
	i = 0;
	while (i < chunks)
	{
		s.start = i * size;
		if (i == chunks - 1)
			s.end = total_size - 1;
		else
			s.end = s.start + size - 1;
		while (in_range(*s.stack_a, arr, s.start, s.end))
			nearest_num(s, arr);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:14:20 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/05 22:32:34 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_list(t_list *stack_a)
{
	t_list	*tmp;

	if (!stack_a)
		return ;
	while (stack_a)
	{
		tmp = stack_a->next;
		free(stack_a);
		stack_a = tmp;
	}
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
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

void	freeall(t_list **stack_a, t_list **stack_b, t_options **options)
{
	free_list(*stack_a);
	*stack_a = NULL;
	free_list(*stack_b);
	*stack_b = NULL;
	if (*options)
	{
		free((*options)->options);
		free(*options);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:14:20 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/08 17:37:30 by ncaravac         ###   ########.fr       */
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

void	free_all(t_list **stack_a, t_list **stack_b, t_options **options)
{
	free_list(*stack_a);
	*stack_a = NULL;
	free_list(*stack_b);
	*stack_b = NULL;
	if (options && *options)
	{
		free((*options)->options);
		free(*options);
		*options = NULL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:51:29 by ncaravac          #+#    #+#             */
/*   Updated: 2025/12/30 04:10:35 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	index_error(int n, t_list *stack_a)
{
	t_list	*tmp;
	int		even_total;
	int		errors;
	float	index;

	even_total = (n * (n - 1)) / 2;
	errors = 0;
	while (stack_a && stack_a->next)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (*(long *)stack_a->content > *(long *)tmp->content)
				errors++;
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	index = (float)errors / even_total;
	return (index);
}

void	free_list(t_list *stack_a)
{
	int	i;
	t_list	*tmp;

	if (!stack_a)
		return ;
	while (stack_a)
	{
		tmp = stack_a->next;
		free(stack_a->content);
		free(stack_a);
		stack_a = tmp;
	}
	free(stack_a);
}

int	for_argv(int argc, char **argv, t_list *stack_a, t_list *stack_b)
{
	t_list	*node;
	int		i;

	i = 0;
	if (!check_num(argv) || !check_minmax(argv))
		return (printf("Error\n"), 0);
	i = 1;
	while (i < argc)
	{
		node = ft_lstnew(ft_atol(argv[i]));
		if (!node)
			return (0);
		ft_lstadd_back(&stack_a, node);
		i++;
	}
	index_error(i, stack_a);
	simple(&stack_a, &stack_b);
	free_list(stack_a);
	return (1);
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

int	for_split(int argc, char **argv, t_list *stack_a, t_list *stack_b)
{
	char	**split;
	t_list	*node;
	int		i;

	i = 0;
	split = ft_split(argv[1], ' ');
	if (!check_num(split) || !check_minmax(split))
	{
		free_split(split);
		return (printf("Error\n"), 0);
	}
	else
		printf("OK\n");
	while (split[i])
	{
		node = ft_lstnew(ft_atol(split[i]));
		if (!node)
			return (0);
		free(split[i]);
		ft_lstadd_back(&stack_a, node);
		i++;
	}
	free(split);
	index_error(i, stack_a);
	free_list(stack_a);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (printf("Error\n"), 0);
	else if (argc == 2)
		for_split(argc, argv, stack_a, stack_b);
	else if (argc > 2)
		for_argv(argc, argv, stack_a, stack_b);
	return (0);
}

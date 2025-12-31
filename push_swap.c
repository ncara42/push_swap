/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:51:29 by ncaravac          #+#    #+#             */
/*   Updated: 2025/12/31 09:32:17 by ncaravac         ###   ########.fr       */
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
			if (stack_a->content > tmp->content)
				errors++;
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	index = (float)errors / (float)even_total;
	return (index);
}

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

int	for_argv(int argc, char **argv, t_list **stack_a)
{
	t_list	*node;
	int		i;

	i = 0;
	if (!check_num(argv) || !check_minmax(argv))
		return (printf("Error\n"), 0);
	*stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		node = ft_lstnew(ft_atol(argv[i]));
		if (!node)
			return (0);
		ft_lstadd_back(stack_a, node);
		i++;
	}
	index_error(i, *stack_a);
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

int	for_split(char **argv, t_list **stack_a)
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
		ft_lstadd_back(stack_a, node);
		i++;
	}
	free(split);
	index_error(i, *stack_a);
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
		for_split(argv, &stack_a);
	else if (argc > 2)
		for_argv(argc, argv, &stack_a);
	complex(&stack_a, &stack_b, ft_lstsize(stack_a));
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:51:29 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/07 17:37:47 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

float	disorder_index(int n, t_list *stack_a)
{
	t_list	*tmp;
	float	even_total;
	float	errors;
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
	index = (errors * 100) / even_total;
	return (index);
}

int	add_node(char *argv, t_list **stack_a)
{
	t_list	*node;

	node = ft_lstnew(ft_atol(argv));
	if (!node)
		return (0);
	ft_lstadd_back(stack_a, node);
	return (1);
}

int	parse_params(int argc, char **argv, t_list **stack_a)
{
	int	i;
	int	count;

	if (!check_num(argv + 1) || !check_minmax(argv + 1))
		return (write(2, "Error\n", 6), 0);
	*stack_a = NULL;
	i = 1;
	count = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			i++;
			continue ;
		}
		if (!add_node(argv[i], stack_a))
			return (write(2, "Error\n", 6), 0);
		count++;
		i++;
	}
	if (count > 0)
		disorder_index(count, *stack_a);
	return (1);
}

int	parse_split(char **argv, t_list **stack_a)
{
	char	**split;
	t_list	*node;
	int		i;

	i = 0;
	split = ft_split(argv[1], ' ');
	if (!split)
		return (0);
	if (!check_num(split) || !check_minmax(split))
		return (free_split(split), write(2, "Error\n", 6), 0);
	while (split[i])
	{
		node = ft_lstnew(ft_atol(split[i++]));
		if (!node)
			return (free_split(split), 0);
		ft_lstadd_back(stack_a, node);
	}
	free_split(split);
	if (i > 0)
		disorder_index(i, *stack_a);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_options	*options;

	stack_a = NULL;
	stack_b = NULL;
	options = NULL;
	if (argc == 1)
		return (write(2, "Error\n", 6), 0);
	else if (argc == 2)
	{
		if (!parse_split(argv, &stack_a))
			return (0);
	}
	else if (argc > 2)
	{
		if (!parse_params(argc, argv, &stack_a))
			return (0);
	}
	parse_options(argc, argv, &options);
	adaptive(&stack_a, &stack_b, &options);
	//medium(&stack_a, &stack_b);
	/*t_list *tmp = stack_a;
	while (tmp)
	{
		printf("%ld\n", tmp->content);
		tmp = tmp->next;
	}*/
	free_all(&stack_a, &stack_b, &options);
	return (0);
}

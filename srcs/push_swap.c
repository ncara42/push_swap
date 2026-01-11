/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:51:29 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/11 04:18:09 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

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
	int			i;
	int			count;
	t_flags		flags;

	flags = (t_flags){0};
	*stack_a = NULL;
	i = (check_flags(argc, argv, flags));
	if (i == -1 || i > 3)
		return (write(2, "Error\n", 6), 0);
	if (!check_num(argv + i) || !check_minmax(argv + i))
		return (write(2, "Error\n", 6), 0);
	count = 0;
	while (i < argc)
	{
		if (!add_node(argv[i], stack_a))
			return (write(2, "Error\n", 6), 0);
		count++;
		i++;
	}
	if (count > 0)
		disorder_index(count, *stack_a);
	return (1);
}

int	parse_split(int argc, char **argv, t_list **stack_a)
{
	char	**split;
	t_list	*node;
	int		i;
	t_flags	flags;

	i = 0;
	flags = (t_flags){0};
	i = (check_flags(argc, argv, flags));
	if (i == -1 || i > 3)
		return (write(1, "Error\n", 6), 0);
	split = ft_split(argv[i], ' ');
	if (!split)
		return (write(1, "Error\n", 6), 0);
	if (!check_num(split) || !check_minmax(split))
		return (free_split(split), write(2, "Error\n", 6), 0);
	*stack_a = NULL;
	i = 0;
	while (split[i])
	{
		node = ft_lstnew(ft_atol(split[i++]));
		if (!node)
			return (free_split(split), 0);
		ft_lstadd_back(stack_a, node);
	}
	return (free_split(split), 1);
}

int	first_check(int argc, char **argv, t_stacks s)
{
	if (argc == 1)
		return (write(2, "Error\n", 6), 0);
	else if (argc == 3 || argc == 4)
	{
		if (!parse_split(argc, argv, s.stack_a))
			return (0);
	}
	else if (argc > 2)
	{
		if (!parse_params(argc, argv, s.stack_a))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_options	*options;
	t_stacks	s;

	stack_a = NULL;
	stack_b = NULL;
	s.stack_a = &stack_a;
	s.stack_b = &stack_b;
	options = NULL;
	if (!first_check(argc, argv, s))
		return (0);
	parse_options(argc, argv, &options);
	adaptive(s, &options);
	free_all(&stack_a, &stack_b, &options);
	return (0);
}

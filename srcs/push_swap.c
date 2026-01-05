/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:51:29 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/06 00:07:10 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	add_node(char *argv, t_list **stack_a)
{
	t_list	*node;

	if (!check_num(argv) || !check_minmax(argv))
		return (0);
	node = ft_lstnew(ft_atol(argv));
	if (!node)
		return (0);
	ft_lstadd_back(stack_a, node);
	return (1);
}

int	parsestack(int argc, char **argv, t_list **stack_a)
{
	int	i;
	int	count;

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
		index_error(count, *stack_a);
	return (1);
}

int	for_split(char **argv, t_list **stack_a)
{
	char	**split;
	t_list	*node;
	int		i;

	i = 0;
	split = ft_split(argv[1], ' ');
	if (!split)
		return (0);
	while (split[i])
	{
		if (!check_num(split[i]) || !check_minmax(split[i]))
			return (free_split(split), write(1, "Error\n", 6), 0);
		i++;
	}
	i = 0;
	while (split[i])
	{
		node = ft_lstnew(ft_atol(split[i++]));
		if (!node)
			return (free_split(split), 0);
		ft_lstadd_back(stack_a, node);
	}
	free_split(split);
	if (count > 0)
		index_error(i, *stack_a);
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
		return (write(1, "Error\n", 6), 0);
	else if (argc == 2)
	{
		if (!for_split(argv, &stack_a))
			return (0);
	}
	else if (argc > 2)
	{
		if (!parsestack(argc, argv, &stack_a))
			return (0);
	}
	parseoptions(argc, argv, &options);
	chooseandusealgo(&stack_a, &stack_b, &options);
	ft_printf("%s\n", "Val, marica");
	freeall(&stack_a, &stack_b, &options);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:51:29 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/04 01:41:42 by vvan-ach         ###   ########.fr       */
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

int	parsestack(int argc, char **argv, t_list **stack_a)
{
	t_list	*node;
	int		i;
	int		count;
	int		parsing_numbers;

	*stack_a = NULL;
	i = 1;
	count = 0;
	parsing_numbers = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench") == 0
			|| (argv[i][0] == '-' && argv[i][1] == '-'))
		{
			parsing_numbers = 0;
			i++;
			continue ;
		}
		if (!check_num(argv[i]) || !check_minmax(argv[i]))
			return (write(1, "Error\n", 6), 0);
		if (parsing_numbers == 0)
			return (write(1, "Error\n", 6), 0);
		node = ft_lstnew(ft_atol(argv[i]));
		if (!node)
			return (0);
		ft_lstadd_back(stack_a, node);
		count++;
		i++;
	}
	index_error(count, *stack_a);
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
	if (argc == 2)
	{
		if (!for_split(argv, &stack_a))
			return (0);
	}
	else
	{
		if (!parsestack(argc, argv, &stack_a))
			return (0);
		if (parseoptions(argc, argv, &options) == 3 || options->count > 2)
			return (write(1, "Wrong options usage\n", 20), 0);
	}
	chooseandusealgo(&stack_a, &stack_b, &options);
	freeall(&stack_a, &stack_b, &options);
	return (0);
}

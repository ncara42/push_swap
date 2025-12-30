#include "push_swap.h"

int	get_min(t_list *stack_a)
{
	int	min;
	int	pos_min;
	int	pos_current;

	if (!stack_a)
		return (0);
	min = *(long *)stack_a->content;
	pos_min = 0;
	pos_current = 0;
	while (stack_a)
	{
		if (*(long *)stack_a->content < min)
		{
			min = *(long *)stack_a->content;
			pos_min = pos_current;
		}
		stack_a = stack_a->next;
		pos_current++;
	}
	return (pos_min);
}

void	simple(t_list **stack_a, t_list **stack_b)
{
	int	nodes;
	int	pos_min;
	
	while (ft_lstsize(*stack_a) > 0)
	{
		pos_min = get_min(*stack_a);
		nodes = ft_lstsize(*stack_a);
		if (pos_min <= nodes / 2)
		{
			while (pos_min > 0)
			{
				ra(stack_a);
				pos_min--;
			}
		}
		else
		{
			while (pos_min < nodes)
			{
				rra(stack_a);
				pos_min++;
			}
		}
		pb(stack_a, stack_b);
	}

	while (ft_lstsize(*stack_b) > 0)
	{
		nodes = ft_lstsize(*stack_b);
		pa(stack_a, stack_b);
	}
}
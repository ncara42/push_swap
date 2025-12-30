#include "push_swap.h"

int	get_min(t_list *stack_a)
{
	int	min;
	int	pos_min;
	int	pos_current;

	
	if (!stack_a)
		return (0);
	min = *(long *)stack_a->content;
	pos_min = 1;
	pos_current = 1;
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
	printf("%d\n", pos_min);
	return (pos_min);
}

void	simple(t_list **stack_a, int nodes)
{
	int	pos_min;
	pos_min = get_min(*stack_a);
	if (pos_min <= nodes / 2)
	{
		printf("Menos de la mitad\n");
		while (pos_min-- > 0)
			ra(stack_a);
	}
	else
	{
		printf("Mas de la mitad\n");
		while (pos_min++ < nodes)
			rra(stack_a);
	}
}
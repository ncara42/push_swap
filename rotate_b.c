#include "push_swap.h"

void	rb(t_list **stack_b)
{
	t_list	*first;
	t_list	*last;

	first = *stack_b;
	*stack_b = first->next;
	first->next = NULL;

	last = ft_lstlast(*stack_b);
	last->next = first;

	write(1, "rb\n", 3);
}

void	rrb(t_list **stack_b)
{
	t_list	*last;
	t_list	*tmp;

	tmp = *stack_b;
	while (tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
	tmp->next = *stack_b;
	*stack_b = tmp;
    
	write(1, "rrb\n", 4);
}
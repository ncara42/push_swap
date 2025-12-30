#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;

	first = *stack_a;
	*stack_a = first->next;
	first->next = NULL;

	last = ft_lstlast(*stack_a);
	last->next = first;

	write(1, "ra\n", 3);
}

void	rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
    
	write(1, "rra\n", 4);
}
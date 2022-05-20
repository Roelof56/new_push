#include "push_swap.h"

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_list **head_a, t_bool print)
{
	t_list	*stack_a;
	t_list	*current_last;
	int		len;

	stack_a = *(head_a);
	len = ft_lstsize(stack_a);
	if (len <= 1)
		return ;
	current_last = ft_lstlast(stack_a);
	current_last->next = stack_a;
	while (stack_a->next->nbr != current_last->nbr)
		stack_a = stack_a->next;
	stack_a->next = NULL;
	*(head_a) = current_last;
	if (print == true)
		write(1, "rra\n", 4);
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_list **head_b, t_bool print)
{
	t_list	*stack_b;
	t_list	*current_last;
	int		len;

	stack_b = *(head_b);
	len = ft_lstsize(stack_b);
	if (len <= 1)
		return ;
	current_last = ft_lstlast(stack_b);
	current_last->next = stack_b;
	while (stack_b->next->nbr != current_last->nbr)
		stack_b = stack_b->next;
	stack_b->next = NULL;
	*(head_b) = current_last;
	if (print == true)
		write(1, "rrb\n", 4);
}

// rrr : rra and rrb at the same time.
void	rrr(t_list **head_a, t_list **head_b)
{
	rra(head_a, false);
	rrb(head_b, false);
	write(1, "rrr\n", 4);
}

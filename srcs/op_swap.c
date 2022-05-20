#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(t_list **head_a, t_bool print)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;

	if (ft_lstsize(*(head_a)) <= 1)
		return ;
	//current list.
	head = *(head_a);
	second = head->next;
	third = head->next->next;
	//re-assign.
	head->next = third;
	second->next = head;
	*(head_a) = second;

	if (print == true)
		write(1, "sa\n", 3);
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_list **head_b, t_bool print)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;

	if (ft_lstsize(*(head_b)) <= 1)
		return ;
	//current list.
	head = *(head_b);
	second = head->next;
	third = head->next->next;
	//re-assign.
	head->next = third;
	second->next = head;
	*(head_b) = second;
	if (print == true)
		write(1, "sb\n", 3);
}

// ss : sa and sb at the same time.
void	ss(t_list **head_a, t_list **head_b)
{
	sa(head_a, false);
	sb(head_b, false);
	write(1, "ss\n", 3);
}

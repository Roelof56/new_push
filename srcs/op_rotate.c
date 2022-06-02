/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhol <rhol@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 14:59:42 by rhol          #+#    #+#                 */
/*   Updated: 2022/06/02 14:59:43 by rhol          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_list **head_a, t_bool print)
{
	t_list	*stack_a;
	t_list	*last;

	stack_a = *(head_a);
	if (ft_lstsize(stack_a) <= 1)
		return ;
	*(head_a) = stack_a->next;
	last = ft_lstlast(stack_a);
	last->next = stack_a;
	stack_a->next = NULL;
	if (print == true)
		write(1, "ra\n", 3);
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_list **head_b, t_bool print)
{
	t_list	*stack_b;
	t_list	*last;

	stack_b = *(head_b);
	if (ft_lstsize(stack_b) <= 1)
		return ;
	*(head_b) = stack_b->next;
	last = ft_lstlast(stack_b);
	last->next = stack_b;
	stack_b->next = NULL;
	if (print == true)
		write(1, "ra\n", 3);
}

// rr : ra and rb at the same time.
void	rr(t_list **head_a, t_list **head_b)
{
	ra(head_a, false);
	rb(head_b, false);
	write(1, "rr\n", 3);
}

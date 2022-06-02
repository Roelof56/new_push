/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhol <rhol@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 14:59:35 by rhol          #+#    #+#                 */
/*   Updated: 2022/06/02 15:05:10 by rhol          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty
void	pb(t_list **head_a, t_list **head_b)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (!*(head_a))
		return ;
	stack_a = *(head_a);
	stack_b = *(head_b);
	*(head_a) = stack_a->next;
	if (!stack_b)
		stack_a->next = NULL;
	else
		stack_a->next = stack_b;
	*(head_b) = stack_a;
	write(1, "pb\n", 3);
}

// (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_list **head_a, t_list **head_b)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (!*(head_b))
		return ;
	stack_a = *(head_a);
	stack_b = *(head_b);
	*(head_b) = stack_b->next;
	if (!stack_a)
		stack_b->next = NULL;
	else
		stack_b->next = stack_a;
	*(head_a) = stack_b;
	write(1, "pa\n", 3);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_less.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhol <rhol@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 14:59:26 by rhol          #+#    #+#                 */
/*   Updated: 2022/06/30 13:22:05 by rhol          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** find the lowest nbr in list head. put it on the pointer adress.
** returns int wich is the location in the list of the lowest number found.
*/
static int	get_lowest(t_list *head, int *low)
{
	t_list	*copy;
	int		lowest_nbr;
	int		lowest_loc;
	int		i;

	copy = head;
	lowest_nbr = INT_MAX;
	lowest_loc = 0;
	i = 0;
	while (copy)
	{
		if (copy->nbr < lowest_nbr)
		{
			lowest_nbr = copy->nbr;
			lowest_loc = i;
		}
		i++;
		copy = copy->next;
	}
	*low = lowest_nbr;
	return (lowest_loc);
}

/*
** push lowest number from stack_a to b until 3 listitems are left.
*/
static void	split_stack(t_list **head_a, t_list **head_b)
{
	int	len_a;
	int	low_loc;
	int	current_low;

	len_a = ft_lstsize(*(head_a));
	while (len_a > 3)
	{
		low_loc = get_lowest(*(head_a), &current_low);
		if (low_loc <= (len_a / 2))
		{
			while ((*(head_a))->nbr != current_low)
				ra(head_a, true);
		}
		else
		{
			while ((*(head_a))->nbr != current_low)
				rra(head_a, true);
		}
		pb(head_a, head_b);
		len_a = ft_lstsize(*(head_a));
	}
}

static void	handle_three(t_list **head)
{
	int		one;
	int		two;
	int		three;

	one = (*(head))->nbr;
	two = (*(head))->next->nbr;
	three = (*(head))->next->next->nbr;
	if (one > two && two < three && three > one)
		sa(head, true);
	else if (one > two && two > three && three < one)
	{
		sa(head, true);
		rra(head, true);
	}
	else if (one > two && two < three && three < one)
		ra(head, true);
	else if (one < two && two > three && three < one)
		rra(head, true);
	else if (one < two && two > three && three > one)
	{
		sa(head, true);
		ra(head, true);
	}
}

/*
** Say something usefull about this.
*/
void	handle_less(t_list **head_a, t_list **head_b)
{
	int	len_a;

	len_a = ft_lstsize(*(head_a));
	if (len_a < 3)
	{
		if ((*(head_a))->nbr > (*(head_a))->next->nbr)
			sa(head_a, true);
		return ;
	}
	else
		split_stack(head_a, head_b);
	handle_three(head_a);
	while (*(head_b))
		pa(head_a, head_b);
}

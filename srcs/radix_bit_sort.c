/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_bit_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhol <rhol@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 14:59:55 by rhol          #+#    #+#                 */
/*   Updated: 2022/06/30 15:54:15 by rhol          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// invert all bits. '~' operator is 'not'
static int	flip_bits(int n)
{
	int	new;

	new = ~n;
	return (new);
}

// returns the vallue of a bit on location loc in the number n.
static int	get_bit(int n, int loc)
{
	int	i;

	i = n >> loc & 1;
	return (i);
}

// loop argument list. when an negative int is found. invert all them bits.
static t_bool	bit_flip_negative(t_list *head)
{
	t_bool	contains_negative;

	contains_negative = false;
	while (head)
	{
		if (head->sign == -1)
		{
			head->nbr = flip_bits(head->nbr);
			contains_negative = true;
		}
		head = head->next;
	}
	return (contains_negative);
}

/*
** if a to be sorted integer is negative. push from a to b.
** push em back if all are out.
*/
static void	handle_subzero_ints(t_list **head_a, t_list **head_b, int len)
{
	int	i;

	bit_flip_negative(*(head_a));
	i = 0;
	while (i < len && *(head_a))
	{
		if (get_bit((*(head_a))->nbr, 31) == 1)
			pb(head_a, head_b);
		else
			ra(head_a, true);
		i++;
	}
	while (*(head_b))
	{
		rrb(head_b, true);
		pa(head_a, head_b);
	}
}

// helper function to print stack binary. // DELETE
static void print_binary(int n)
{
	int	i;
	int	j;

	i = 31;
	j = 0;
	printf("%10d : ", n);
	while (i >= 0)
	{
		if (j % 4 == 0)
			printf(" ");
		printf("%d", get_bit(n, i));
		i--;
		j++;
	}
	printf("\n");
}

// temp print function. // DELETE 
void print_stack_binary(t_list *head)
{
	while (head)
	{
		printf("sign: %4d ", head->sign);
		print_binary(head->nbr);
		head = head->next;
	}
}
// END DELETE STUFF.

//testie time. v5 special.
t_bool	list_has_same_bit_val(t_list *head_a, int i, int val)
{
	// printf("hi\n");
	while (head_a)
	{
		if (get_bit(head_a->nbr, i) == val)
		{
			head_a = head_a->next;
			continue ;
		}
		else
			return (false);
	}
	return (true);
}

/*
**	sort based on bit vallue right to left.
*/
void	radix_bit_sort(t_list **head_a, t_list **head_b, int len)
{
	int		i;
	int		j;
	t_bool	contains_negative;

	i = 0;
	contains_negative = bit_flip_negative(*(head_a));
	while (i < 31)
	{
		j = 0;
		while (j < len)
		{
			if (get_bit((*(head_a))->nbr, i) == 1 && j == 0)
			{
				if (list_has_same_bit_val(*(head_a), i, 1) == true)
				{
					j++;
					continue ;
				}
			}
			if (get_bit((*(head_a))->nbr, i) == 0)
				pb(head_a, head_b);
			else
				ra(head_a, true);
			j++;
		}
		while (*(head_b))
			pa(head_a, head_b);
		if (is_sorted(*(head_a)))
			break ;
		i++;
	}
	if (contains_negative == true)
		handle_subzero_ints(head_a, head_b, len);
	// printf("count ra = %d\n len = %d\n", count_ra, len);
}

#include "push_swap.h"

// invert all bits. '~' operator is 'not'
static int	flip_bits(int n)
{
	int new;

	new = ~n;
	return (new);
}

// n is the number - loc(ation) is wich bit to get (0 is right most bit 31 is left.).
// returns 1 || 0 for that bit loc.
static int get_bit(int n, int loc)
{
	int	i;
	
	i = n>>loc&1;
	return (i);
}

static void	bit_flip_negative(t_list *list) // remove the copy ? !
{
	t_list	*cpy;

	cpy = list;
	while (cpy)
	{
		if (cpy->sign == -1)
			cpy->nbr = flip_bits(cpy->nbr);
		cpy = cpy->next;
	}
}

/*
**	sort based on bit vallue left to right.
*/
void	radix_bit_sort(t_list **head_a, t_list **head_b)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	// print the incomming list.
	// print_stack_binary(program->head_a);

	// flip them bits
	bit_flip_negative(*(head_a));

	//print after flip
	// print_stack_binary(program->head_a);

	// sort some stuff.

	len = ft_lstsize(*(head_a));
	while (i < 31)
	{
		j = 0;
		while (j < len)
		{
			if (get_bit((*(head_a))->nbr, i) == 0)
			{
				pb(head_a, head_b);
			}
			else
				ra(head_a, true);
			j++;
		}
		// print_stacks(program);
		while (*(head_b))
			pa(head_a, head_b);
		// print_stacks(program);
		if (is_sorted(*(head_a)))
			break ;
		i++;
	}
	//revert numbers back to original.
	bit_flip_negative(*(head_a));
	// print_stacks(program);

	//put negatives back in in reverse order.
	i = 0;
	// check if there are negatives to trigger this.
	// no there are exta operations for bull.
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

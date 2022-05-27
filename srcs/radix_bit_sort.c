#include "push_swap.h"

// invert all bits. '~' operator is 'not'
static int	flip_bits(int n)
{
	int new;

	new = ~n;
	return (new);
}

// returns the vallue of a bit on location loc in the number n.
static int get_bit(int n, int loc)
{
	int	i;
	
	i = n>>loc&1;
	return (i);
}

static void	bit_flip_negative(t_list *head)
{
	while (head)
	{
		if (head->sign == -1)
			head->nbr = flip_bits(head->nbr);
		head = head->next;
	}
}

// helper function to print stack binary.
static void print_binary(int n)
{
	int	i;
	int	j;

	i = 31;
	j = 0;
	printf("%14d : ", n);
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

// temp print function.
static void print_stack_binary(t_list *head)
{
	while (head)
	{
		printf("sign: %4d ", head->sign);
		print_binary(head->nbr);
		head = head->next;
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
	printf("original stack: \n");
	print_stack_binary(*(head_a));

	// flip them bits
	bit_flip_negative(*(head_a));
	
	//print after flip
	printf("\nafter bit flip: \n");
	print_stack_binary(*(head_a));

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
		print_stacks(*(head_a), *(head_b));
		while (*(head_b))
			pa(head_a, head_b);
		print_stacks(*(head_a), *(head_b));
		if (is_sorted(*(head_a)))
			break ;
		i++;
	}
	//revert numbers back to original.
	bit_flip_negative(*(head_a));
	print_stacks(*(head_a), *(head_b));

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

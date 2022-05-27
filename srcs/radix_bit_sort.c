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

// helper function to print stack binary.
static void	print_binary(int n)
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
static void	print_stack_binary(t_list *head)
{
	while (head)
	{
		printf("sign: %4d ", head->sign);
		print_binary(head->nbr);
		head = head->next;
	}
}

static void	handle_subzero_ints(t_list **head_a, t_list **head_b, int len)
{
	int	i;

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

/*
**	sort based on bit vallue left to right.
*/
void	radix_bit_sort(t_list **head_a, t_list **head_b)
{
	int		i;
	int		j;
	int		len;
	t_bool	contains_negative;

	i = 0;
	contains_negative = bit_flip_negative(*(head_a));
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
		while (*(head_b))
			pa(head_a, head_b);
		if (is_sorted(*(head_a)))
			break ;
		i++;
	}
	if (contains_negative == true)
	{
		bit_flip_negative(*(head_a));
		handle_subzero_ints(head_a, head_b, len);
	}
}

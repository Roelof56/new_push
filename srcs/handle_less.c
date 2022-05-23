#include "push_swap.h"

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

static void	get_lowest_two(t_list *head, t_low_info *data)
{
	int	i;

	i = 0;
	data->low = INT_MAX;
	data->sec_low = INT_MAX;
	while (head)
	{
		if (head->nbr < data->low)
		{
			data->low = head->nbr;
			data->l_loc = i;
		}
		else if (head->nbr < data->sec_low && head->nbr > data->low)
		{
			data->sec_low = head->nbr;
			data->sl_loc = i;
		}
		i++;
		head = head->next;
	}
}

static void	handle_two(t_list **head)
{
	int		one;
	int		two;

	one = (*(head))->nbr;
	two = (*(head))->next->nbr;
	if (one > two)
		sa(head, true);
	return ;
}

static void	split_stack(t_list **head_a, t_list **head_b)
{
	int	len_a;
	int	low_loc;
	int	current_low;

	len_a = ft_lstsize(*(head_a));
	while (len_a > 3)
	{
		low_loc = get_lowest((*(head_a)), &current_low);
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

void	handle_less(t_list **head_a, t_list **head_b)
{
	int	len_a;

	len_a = ft_lstsize(*(head_a));
	if (len_a < 3)
	{
		handle_two(head_a);
		return ;
	}
	else
		split_stack(head_a, head_b);
	handle_three(head_a);
	while (*(head_b))
		pa(head_a, head_b);
	// testing time;
	t_low_info data;
	get_lowest_two(*(head_a), &data);
	printf("first low: %d (%d)\n", data.low, data.l_loc);
	printf("second low: %d (%d)\n", data.sec_low, data.sl_loc);
	print_stacks(*(head_a), *(head_b));
}

#include "push_swap.h"

int is_sorted(t_list *head)
{
	t_list *cpy;

	cpy = head;
	while (cpy)
	{
		if (cpy->next != NULL)
		{
			if (cpy->nbr > cpy->next->nbr)
				return (0);
		}
		cpy = cpy->next;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	long	res;
	int		min;
	int		i;

	min = 1;
	res = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
						str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		str++;
	if (str[i] == '-')
		min = -1;
	if (str[i] == '-' || str[i] == '+')
		str++;
	while (str[i] && ft_isdigit(str[i]))
	{
		if (i >= 10 && min == 1)
			return (-1);
		if (i >= 10 && min == -1)
			return (0);
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * min);
}

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list	*a;
	t_list	*b;

	a = stack_a;
	b = stack_b;
	printf("stack:        a   |   b\n");
	printf("       _____________________\n");
	while (a || b)
	{
		if (a)
		{
			printf("  %11d (%2d)|", a->nbr, a->sign);
			a = a->next;
		}
		else
		{
			printf("%14c |", '.');
		}
		
		if (b)
		{
			printf("%4d ", b->nbr);
			b = b->next;
		}
		else
		{
			printf("%4c", '.');
		}
		printf("\n");
	}
	printf("\n");
}

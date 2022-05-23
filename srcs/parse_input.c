#include "push_swap.h"

static int is_valid_int(long x)
{
	if (x < INT_MIN || x > INT_MAX)
		return (-1);
	return (1);
}

static int	check_args(int argc, char **argv)
{
	int i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == 43 || argv[i][j] == 45 || ft_isdigit(argv[i][j]))
			j++;
		else
			return (-1);
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

static int	create_list(int argc, char **argv, t_list **stack_a)
{
	t_list	*new;
	long	tmp;
	int		i;

	i = 1;
	new = NULL;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i]);
		if (is_valid_int(tmp) < 0)
			return (-1); // clean list.
		new = ft_lstnew(tmp);
		if (!new) 
			return (-1); // also clean list.
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return (1);
}

static int	check_for_duplicates(t_list *head)
{
	t_list *cpy;

	while (head)
	{
		cpy = head->next;
		while (cpy)
		{
			if (head->nbr == cpy->nbr)
				return (-1); // printf("DUPLICATE FOUND!\n");
			// printf("%d, %d\n", head->nbr, cpy->nbr); 		//shows comparisons.
			cpy = cpy->next;
		}
		head = head->next;
	}
	return (1);
}

int	import_arguments(int argc, char **argv, t_list **stack_a)
{
	int		i;

	i = 0;
	if (check_args(argc, argv) < 0)
		return (-1);
	if (create_list(argc, argv, stack_a) < 0)
		return (-1);
	if (check_for_duplicates(*(stack_a)) < 0)
		return (-1);
	return (1);
}

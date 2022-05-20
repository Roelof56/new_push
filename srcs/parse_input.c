#include "push_swap.h"

// static int is_valid_int(long int x)
// {
// 	if (x > INT_MAX || x < INT_MIN)
// 		return (-1);
// 	return (1);
// }

int	import_arguments(int argc, char **argv, t_list **stack_a)
{
	int		i;

	i = 0;
	if (create_list(argc, argv, stack_a) < 0)
	{
		printf("test 12\n");
		return (-1);
	}
	// print_array(program->array, program->len_a);
	return (1);
}

// malloc protection is important to add. also the loc argument can go!!!
int	create_list(int argc, char **argv, t_list **stack_a)
{
	t_list	*new;
	long	tmp;
	int		i;

	i = 1;
	new = NULL;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i]);
		// if (is_valid_int(tmp) < 0)
		// 	return (-1); // clean list.
		new = ft_lstnew(tmp);
		if (!new) 
			return (-1); // also clean list.
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return (1);
}

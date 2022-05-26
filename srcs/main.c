#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		len;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 2)
		return (0);
	//maybe do spellcheck here instead of inside of import arguments?
	if (import_arguments(argc, argv, &stack_a) < 0)
	{
		write(2, "Error\n", 6); // clean that list.
		return (0);
	}
	if (is_sorted(stack_a) == 1)
	{
		// printf("sorted!\n"); // clean that list.
		return (0);
	}

	// printf("present opening stacks \n");
	// print_stacks(stack_a, stack_b);

	len = ft_lstsize(stack_a);
	if (len <= 50)
		handle_less(&stack_a, &stack_b);
	else
		radix_bit_sort(&stack_a, &stack_b);

	// printf("final stack print:\n");
	// print_stacks(stack_a, stack_b);
	
	// clean_that_list(program.head_a);
	return (0);
}


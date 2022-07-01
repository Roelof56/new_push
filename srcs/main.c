/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhol <rhol@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 14:59:31 by rhol          #+#    #+#                 */
/*   Updated: 2022/07/01 12:24:19 by rhol          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		len;

	stack_a = NULL;
	stack_b = NULL;
	// if (argc <= 2) // gotte error on one argument. -> fixed this can go.
	// 	return (0);
	if (import_arguments(argc, argv, &stack_a) < 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (is_sorted(stack_a) == 1)
	{
		clean_list(stack_a);
		return (0);
	}
	len = ft_lstsize(stack_a);
	if (len <= 5)
		handle_less(&stack_a, &stack_b);
	else
		radix_bit_sort(&stack_a, &stack_b, len);
	print_stacks(stack_a, stack_b);
	print_stack_binary(stack_a);
	clean_list(stack_a);
	return (0);
}

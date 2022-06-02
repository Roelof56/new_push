/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhol <rhol@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 14:57:06 by rhol          #+#    #+#                 */
/*   Updated: 2022/06/02 15:21:16 by rhol          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef enum e_bool { false, true }	t_bool;

typedef struct s_list
{
	int				nbr;
	int				sign;
	struct s_list	*next;
}					t_list;

/* stack operation functions */
/* push */
void	pb(t_list **head_a, t_list **head_b);
void	pa(t_list **head_a, t_list **head_b);
/* reverse */
void	rra(t_list **head_a, t_bool print);
void	rrb(t_list **head_b, t_bool print);
void	rrr(t_list **head_a, t_list **head_b);
/* rotate */
void	ra(t_list **head_a, t_bool print);
void	rb(t_list **head_b, t_bool print);
void	rr(t_list **head_a, t_list **head_b);
/* swap */
void	sa(t_list **head_a, t_bool print);
void	sb(t_list **head_b, t_bool print);
void	ss(t_list **head_a, t_list **head_b);

/* handle_less.c */
void	handle_less(t_list **head_a, t_list **head_b);

/* radix_bit_sort.c */
void	radix_bit_sort(t_list **head_a, t_list **head_b, int len);

/* parse_input.c */
int		import_arguments(int argc, char **argv, t_list **stack_a);

/* utils_list.c */
t_list	*ft_lstnew(int nbr);
void	ft_lstadd_back(t_list **head, t_list *new);
int		ft_lstsize(t_list *head);
t_list	*ft_lstlast(t_list *lst);
void	clean_list(t_list *head);

/* utils.c */
int		is_sorted(t_list *head);
int		ft_isdigit(int c);
long	ft_atoi(const char *str);
void	print_stacks(t_list *stack_a, t_list *stack_b);

#endif

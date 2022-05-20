#include "push_swap.h"

t_list	*ft_lstnew(int nbr)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	new->sign = 1;
	if (nbr < 0)
	{
		// new->nbr = flip_bits(nbr);
		new->nbr = nbr;
		new->sign = -1;
	}
	return (new);
}

void	ft_lstadd_back(t_list **head, t_list *new)
{
	t_list	*tail;

	if (!*head)
	{
		*head = new;
		return ;
	}
	tail = *head;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = new;
}

// void	ft_clear_list(t_list **head)
// {
// 	t_list	*tmp;

// 	if (!*head)
// 		return ;
// 	while ((*head))
// 	{
// 		tmp = (*head)->next;
// 		free((*head));
// 		*head = tmp;
// 	}
// }

int	ft_lstsize(t_list *head)
{
	int		i;
	t_list	*tmp;

	if (!head)
		return (0);
	tmp = head;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	if (!lst || !new)
// 		return ;
// 	new->next = *lst;
// 	*lst = new;
// }

t_list	*ft_lstlast(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	if (lst == NULL)
		return (NULL);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

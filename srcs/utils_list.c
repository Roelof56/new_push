#include "push_swap.h"

t_list	*ft_lstnew(int nbr)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	if (nbr < 0)
		new->sign = -1;
	else
		new->sign = 1;
	return (new);
}

void	ft_lstadd_back(t_list **head, t_list *new)
{
	t_list	*tail;

	if (!*(head))
	{
		*(head) = new;
		return ;
	}
	tail = *(head);
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = new;
}

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

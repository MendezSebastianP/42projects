#include "push_swap.h"

void	r_rot(t_list **list)
{
	t_list	*first;
	t_list	*last;
	t_list	*temp;
	int	i;
	int	k;

	k = 0;
	i = ft_lstsize(*list) - 1;
	first = *list;
	last = ft_lstlast(*list);
	ft_lstadd_front(list, last);
	*list = last;
	temp = *list;
	while (k != i)
	{
		temp = temp->next;
		k++;
	}
	temp->next = NULL;
}

void	rrr(t_list **list_a, t_list ** list_b)
{
	if (!list_a || !*list_a || !list_b || !*list_b)
        	return;
	r_rot(list_a);
	r_rot(list_b);
}

/* int	main(int argc, char *argv[])
{
	// print_single(argv, r_rot);
	print_both(argv, argv + 4, rrr);
	return (0);
} */

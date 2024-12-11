#include "push_swap.h"

void	r_rot(t_list **list)
{
	t_list	*first;
	t_list	*last;
	t_list	*temp;
	t_list	**list2;

	first = *list;
	list2 = list;
	last = ft_lstlast(*list);
	ft_lstadd_front(list, last);
	*list = last;
	// temp = ft_lstlast(*list);
	// temp->next = NULL;
}

int	main(int argc, char *argv[])
{
	print_single(argv, r_rot);
	// print_both(argv, argv + 4, rr);
	return (0);
}

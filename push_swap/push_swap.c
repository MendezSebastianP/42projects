#include "push_swap.h"

int	content_list(t_list *b1, int index)
{
	int	i;
	t_list	*current;

	i = 0;
	if (b1 == NULL)
		return (0);
	if (index == -1)
	{
		current = ft_lstlast(b1);
		return (*(int *)current->content);
	}
	if (ft_lstsize(b1) < index)
		return (0);
	current = b1;
	while (i < index)
		{
			current = current->next;
			i++;
		}
	return (*(int *)current->content);
}

int	test_isok(t_list *b1)
{
	if (b1->next == NULL)
		return (0);
	while (b1->next)
	{
		if (*(int *)b1->content > *(int *)b1->next->content)
			return(0);
		b1 = b1->next;
	}
	return (1);
}


void	swap_algo1(t_list **b1, t_list **b2)
{
	int	i;

	i = 0;
	while (test_isok(*b1) == 0 || *b2)
	{
		ft_printf("    %d\n", i + 1);
		if ((*(int *)(*b1)->content > *(int *)((*b1)->next->content)) && (*(int *)(*b1)->content > *(int*)(ft_lstlast(*b1)->content)))
			rotate(b1);
		else if (*(int *)(*b1)->content > *(int*)(ft_lstlast(*b1)->content))
			r_rot(b1);
		else if (*(int *)(*b1)->content > *(int *)((*b1)->next->content))
			sswap(b1);
		else if (*b2 && test_isok(*b1) == 1 && test_isok(*b2) == 0)
		{
			while(*b2)
				spush(b2, b1);
		}
		else
		{
			while ((*b1)->next && (*(int *)(*b1)->content < *(int *)((*b1)->next->content)))
				spush(b1, b2);
		}
		print_algo(*b1, *b2);
		i++;
	}
}
void	print_s(t_list *b1) // delete
{

	t_list 	*b1_free;
	int	i = 1;
	b1_free = b1;
	ft_printf("   |before|after | \n");
	while (b1 != NULL)
	{
		ft_printf("%d- |__%d___| \n", i++, *(int *)b1->content);
		b1 = b1->next;
	}
}
void	push_test(char **argv)
{
	t_list	*b1;
	t_list	*b2;

	b1 = ptr_to_numblist(argv);
	b2 = NULL;
	swap_algo1(&b1, &b2);
	// print_s(b1);
	//print_algo( b1, b2);
	free_list(b1);
	free_list(b2);
}

int	main(int argc, char *argv[])
{
	push_test(argv);
	return (0);
}
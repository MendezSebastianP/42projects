#include "push_swap.h"

int	content_list(t_list *b1, int index)
{
	int	i;
	t_list	*current;

	i = 0;
	if (b1 == NULL)
		return (NULL);
	if (index == -1)
	{
		current = ft_lstlast(b1);
		return (current->content);
	}
	if (ft_lstsize(b1) < index)
		return (NULL);
	current = b1;
	while (i < index)
		{
			current = current->next;
			i++;
		}
	return (current->content);
}

t_list	*step1(char **argv)
{
	t_list	*b1;
	b1 = ptr_to_numblist(argv);
	return (b1);
}

void	swap_algo1(t_list **b1, t_list **b2)
{
	t_list	*b1a;
	t_list	*b2a;
	int	i;

	b1a = b1;
	b2a = b2;
	if (b1a->content > (int *)(b1a->next->content))
		sswap(&b1a);
	else
	{
		spush(&b1, &b2);
		spush(&b1, &b2);
	}
}

void	push_test(char **argv)
{
	t_list	*b1;
	t_list	*b2;

	b1 = step1 (argv);
	b2 = NULL;
	swap_algo1(&b1, &b2);
	print_algo(&b1, &b2);
}

int	main(int argc, char *argv[])
{
	push_test(argv);
	return (0);
}
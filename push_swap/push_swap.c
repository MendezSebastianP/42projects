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

int	test_isko(t_list *b1)
{
	if (b1->next == NULL)
		return (0);
	while (b1->next)
	{
		if (*(int *)b1->content < *(int *)b1->next->content)
			return(0);
		b1 = b1->next;
	}
	return (1);
}

/* void	swap_algo1(t_list **b1, t_list **b2)
{
	int	i;

	i = 0;
	while (test_isok(*b1) == 0 || *b2)
	{
		ft_printf("    %d\n", i + 1);
		if (*b1 && *b2 && (*b1)->next && (*b2)->next  &&  (*(int*)(ft_lstlast(*b1)->content) < *(int *)(*b1)->content) && (*(int *)(*b1)->content > *(int *)((*b1)->next->content)) &&
		(*(int*)(ft_lstlast(*b2)->content) < *(int *)(*b2)->content) && (*(int *)(*b2)->content > *(int *)((*b2)->next->content))) // rr
			rr(b1, b2);
		else if (*b1 && *b2 && (*b1)->next && (*b2)->next  && ((*(int*)(ft_lstlast(*b1)->content) < *(int *)(*b1)->content)) &&
		(*(int*)(ft_lstlast(*b2)->content) < *(int *)(*b2)->content)) // rrr
			rrr(b1, b2);
		else if (*b1 && *b2 && (*b1)->next && (*b2)->next && (*(int *)(*b1)->content > *(int *)((*b1)->next->content)) &&
		(*(int *)(*b2)->content < *(int *)((*b2)->next->content))) //ss
			ss(b1, b2);
		else if  ((*(int *)(*b1)->content > *(int *)((*b1)->next->content)) && (*(int *)(*b1)->content > *(int*)(ft_lstlast(*b1)->content))) // r
			rotate(b1);
		else if (*(int *)(*b1)->content > *(int*)(ft_lstlast(*b1)->content)) // r_r
			r_rot(b1);
		else if (*(int *)(*b1)->content > *(int *)((*b1)->next->content)) // sa
			sswap(b1);
		else if (*b2 && test_isok(*b1) == 1 && test_isko(*b2) == 1) // push b
		{
			while(*b2)
				spush(b2, b1);
		}
		else if (*b2 && test_isok(*b1) == 1 && test_isok(*b2) == 0)
		{
			while(*b2)
				spush(b2, b1);
		}
		else
		{
			while ((*b1) && (*(int *)(*b1)->content < *(int *)((*b1)->next->content))) // push a
				spush(b1, b2);
		}
		print_algo(*b1, *b2);
		i++;
	}
} */
void	swap_algo2(t_list **b1, t_list **b2)
{
	while (test_isok(*b1) == 0 || *b2)
	{
		if (*b1 && *b2 && (*b1)->next && (*b2)->next  &&  (*(int*)(ft_lstlast(*b1)->content) < *(int *)(*b1)->content) && (*(int *)(*b1)->content > *(int *)((*b1)->next->content)) &&
		(*(int*)(ft_lstlast(*b2)->content) < *(int *)(*b2)->content) && (*(int *)(*b2)->content > *(int *)((*b2)->next->content))) // rr
			{
				rr(b1, b2);
				ft_printf("rr\n");
			}
		else if (*b1 && *b2 && (*b1)->next && (*b2)->next  && ((*(int*)(ft_lstlast(*b1)->content) < *(int *)(*b1)->content)) &&
		(*(int*)(ft_lstlast(*b2)->content) < *(int *)(*b2)->content)) // rrr
			{
				rrr(b1, b2);
				ft_printf("rrr\n");
			}
		else if (*b1 && *b2 && (*b1)->next && (*b2)->next && (*(int *)(*b1)->content > *(int *)((*b1)->next->content)) &&
		(*(int *)(*b2)->content < *(int *)((*b2)->next->content))) //ss
			{
				rr(b1, b2);
				ft_printf("ss\n");
			}
		else if  ((*(int *)(*b1)->content > *(int *)((*b1)->next->content)) && (*(int *)(*b1)->content > *(int*)(ft_lstlast(*b1)->content))) // r
			{
				rotate(b1);
				ft_printf("ra\n");
			}
		else if (*(int *)(*b1)->content > *(int*)(ft_lstlast(*b1)->content)) // r_ra
			{
				r_rot(b1);
				ft_printf("rra\n");
			}
		else if (*b2 && *(int *)(*b2)->content < *(int*)(ft_lstlast(*b2)->content)) // r_rb
			{
				r_rot(b2);
				ft_printf("rrb\n");
			}
		else if (*(int *)(*b1)->content > *(int *)((*b1)->next->content)) // sa
			{
				sswap(b1);
				ft_printf("sa\n");
			}
		else if (*b2 && (*b2)->next && *(int *)(*b2)->content < *(int *)((*b2)->next->content)) // sb
			{
				sswap(b2);
				ft_printf("sb\n");
			}
		else if (*b2 && test_isok(*b1) == 1 && test_isko(*b2) == 1) // push b
		{
			while(*b2)
			{
				spush(b2, b1);
				ft_printf("pb\n");
			}
		}
		else if (*b2 && test_isok(*b1) == 1 && test_isok(*b2) == 0)
		{
			while(*b2)
			{
				spush(b2, b1);
				ft_printf("pb\n");
			}
		}
		else
		{
			while ((*b1) && (*(int *)(*b1)->content < *(int *)((*b1)->next->content))) // push a
			{
				spush(b1, b2);
				ft_printf("pa\n");
			}
		}
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

void	push_swap(int argc, char **argv)
{
	t_list	*b1;
	t_list	*b2;

	b1 = ptr_to_numblist(argv);
	b2 = NULL;
	if (swap_iserror(argc, argv) == 1)
	{
		ft_printf("Error\n");
		return ;
	}
	swap_algo2(&b1, &b2);
	// print_s(b1);
	//print_algo( b1, b2);
	free_list(b1);
	free_list(b2);
}

int	main(int argc, char *argv[])
{
	push_swap(argc, argv);
	return (0);
}

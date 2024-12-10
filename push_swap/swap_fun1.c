#include "push_swap.h"

t_list	*ptr_to_list(int argc, char *argv[])
{
	int	i;
	t_list	*newob;
	t_list	*newlst;

	i = 1;
	newlst = NULL;
	while(argv[i])
	{
		newob = ft_lstnew(argv[i]);
		if (!newob)
			return (NULL);
		ft_lstadd_back(&newlst, newob);
		i++;
	}
	return (newlst);
}

void sswap(t_list **list)
{
	t_list *first;
	t_list *second; 

	if (!list || !*list || !(*list)->next)
        	return;
	first = *list;
	second = (*list)->next;
	first->next = second->next;
	second->next = first;
	*list = second; 
}

void spush(t_list **list_a, t_list **list_b)
{
	t_list *first_a;
	t_list *first_b;
	t_list	*temp;

	if (!list_a || !*list_a || !list_b || !*list_b )
        	return;
	first_a = *list_a;
	first_b = *list_b;
	temp = *list_a;
	temp->next = first_a->next;
	first_a->next = first_b->next;
	first_b->next = temp->next;
	*list_a = first_b;
	*list_b = first_a;
}

/* int	main(int argc, char *argv[])
{
	t_list 	*b1;
	t_list	*b1a;
	int	i = 1;

	b1 = ptr_to_list(argc, argv);
	b1a = ptr_to_list(argc, argv);
	sswap(&b1a);
	while (b1 != NULL)
	{
		ft_printf("%d- |__%s__|__%s__| \n",
		 i++, b1->content, b1a->content);
		b1 = b1->next;
		b1a = b1a->next;
	}
	return (0);
} */

int	main(int argc, char *argv[])
{
	t_list 	*b1;
	t_list	*b1a;
	int	i = 1;

	b1 = ptr_to_list(argc, argv);
	b1a = ptr_to_list(argc, argv);
	sswap(&b1a);
	while (b1 != NULL)
	{
		ft_printf("%d- |__%s__|__%s__| \n",
		 i++, b1->content, b1a->content);
		b1 = b1->next;
		b1a = b1a->next;
	}
	return (0);
}

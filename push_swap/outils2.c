#include "push_swap.h"

void free_list(t_list *list)
{
    t_list *tmp;

    while (list)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

t_list	*ptr_to_list(char *argv[])
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

void	print_single(char **argv, void (f)(t_list **))
{
	t_list 	*b1;
	t_list	*b1a;
	t_list 	*b1_free;
	t_list	*b1a_free;
	int	i = 1;

	b1 = ptr_to_list(argv);
	b1a = ptr_to_list(argv);
	b1_free = b1;
	b1a_free = b1a;
	f(&b1a);
	ft_printf("   |before|after | \n");
	while (b1 != NULL)
	{
		ft_printf("%d- |__%s___|__%s___| \n", i++, b1->content, b1a->content);
		b1 = b1->next;
		b1a = b1a->next;
	}
	free_list(b1_free);
	free_list(b1a_free);
}

void	print_both(char **argv1, char **argv2, void (f)(t_list **, t_list **))
{
	t_list *b1;
	t_list *b1a;
	t_list *tmp1;
	t_list *tmp2;
	int i = 1;

	b1 = ptr_to_list(argv1);
	b1a = ptr_to_list(argv2);
	if (!b1 || !b1a)
	{
		ft_printf("Erreur lors de la création des listes.\n");
		free_list(b1);
		free_list(b1a);
		return;
	}
	f(&b1, &b1a);
	tmp1 = b1;
	tmp2 = b1a;
	while (tmp1 != NULL || tmp2 != NULL)
	{
		ft_printf("%d- ", i++);
		if (tmp1)
		{
			ft_printf("|__%s__|", (char *)tmp1->content);
			tmp1 = tmp1->next;
		}
		if (tmp2)
		{
			ft_printf("|__%s__|", (char *)tmp2->content);
			tmp2 = tmp2->next;
		}
		ft_printf("\n");
	}
	free_list(b1);
	free_list(b1a);
}

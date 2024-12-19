#include "push_swap.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] == 32 || (s[i] > 8 && s[i] < 14))
		i++;
	while ((s[i] < 48 || s[i] > 57) && s[i] != '\0')
	{
		if (s[i] == 45 && s[i + 1] != 43 && j < 1)
			j++;
		else if (s[i] != 43 || s[i + 1] == 43 || s[i + 1] == 45)
			return (0);
		i++;
	}
	while (s[i] > 47 && s[i] < 58)
	{
		k = k * 10 + s[i] - 48;
		i++;
	}
	if (j == 1)
		return (k * -1);
	return (k);
}

char *free_list(t_list *list)
{
    t_list *tmp;

    while (list)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
    return (NULL);
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
		{
			free_list(newlst);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newob);
		i++;
	}
	return (newlst);
}
#include <stdio.h>
t_list	*ptr_to_numblist(char *argv[])
{
	int	i;
	t_list	*newob;
	t_list	*newlst;
	int	*number;

	i = 1;
	newlst = NULL;
	while(argv[i])
	{
		number = malloc(sizeof(int));
		if (!number)
			return(NULL);
		*number = ft_atoi(argv[i]);
		newob = ft_lstnew(number);
		if (!newob)
			return (free(number), NULL);
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
	while (b1 != NULL && b1a != NULL)
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

void	print_ex(char **argv)
{
	t_list	*b1;
	t_list	*b2;
	t_list	*tmp1;
	t_list	*tmp2;
	int	i;

	b1 = ptr_to_list(argv);
	// spush(&b1, &b2);
	// spush(&b1, &b2);
	// spush(&b1, &b2);
	// rotate(&b1);
	// rotate(&b1);
	// rotate(&b2);
	// rotate(&b2);
	// ss(&b1, &b2);
	// rr(&b1, &b2);
	// rrr(&b1, &b2);
	// r_rot(&b1);
	// r_rot(&b2);
	tmp1 = b1;
	tmp2 = b2;
	i = 0;
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
	free_list(b2);
}

void	print_algo(t_list *b1, t_list *b2)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int	i;

	tmp1 = b1;
	tmp2 = b2;
	i = 0;
	while (tmp1 != NULL || tmp2 != NULL)
	{
		ft_printf("%d- ", i++);
		if (tmp1)
		{
			ft_printf("|__%d__|", *(int *)tmp1->content);
			tmp1 = tmp1->next;
		}
		if (tmp2)
		{
			ft_printf("|__%d__|", *(int *)tmp2->content);
			tmp2 = tmp2->next;
		}
		ft_printf("\n");
	}
}


/* int	main(int argc, char *argv[])
{
	print_ex(argv);
	return (0);
} */

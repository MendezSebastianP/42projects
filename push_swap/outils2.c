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
	free(tmp->content);
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


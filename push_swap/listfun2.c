#include "push_swap.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*nextptr;

	if (lst == NULL || del == NULL)
		return ;
	else
	{
		current = *lst;
		while (current != NULL)
		{
			nextptr = current->next;
			del(current->content);
			free(current);
			current = nextptr;
		}
	}
	*lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	current = lst;
	if (lst == NULL || f == NULL)
		return ;
	while (current != NULL)
	{
		f(current->content);
		current = current->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newob;
	t_list	*newlst;
	void	*temp_content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	newlst = NULL;
	while (lst != NULL)
	{
		temp_content = f(lst->content);
		newob = ft_lstnew(temp_content);
		if (!newob)
		{
			del(temp_content);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newob);
		lst = lst->next;
	}
	return (newlst);
}


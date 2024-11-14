/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:43:58 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/14 12:59:37 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *nlst;
	t_list *currentPtr;
	
	currentPtr = lst;

	nlst = malloc(sizeof(t_list));
	if (nlst == NULL)
		return (NULL);
	while (currentPtr != NULL)
	{
		f(nlst->content);
		currentPtr = currentPtr->next;
		nlst = nlst->next;
	}
	nlst->next = NULL;
	return (nlst);
	
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *currentPtr;
	
	currentPtr = lst;
	if (lst == NULL || f == NULL)
		return;
	while (currentPtr != NULL)
	{
		f(currentPtr->content);
		currentPtr = currentPtr->next;
	}
}
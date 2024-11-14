/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:27:53 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/14 17:06:15 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>


/* void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*b1;
	
	if (!(*lst))
		return (ft_lstadd_front(lst,new));
	b1 = ft_lstlast(*lst);
	b1->next = new;
} */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *currentPtr;

	currentPtr = *lst;
	// new->next = NULL;
	if (*lst == NULL)
	{
		if (new == NULL)
			return ;
		new->next = *lst;
        	*lst = new;
		return;
	}
	while (currentPtr->next != NULL)
	{
		currentPtr = currentPtr->next;
	}
	currentPtr->next = new;
}
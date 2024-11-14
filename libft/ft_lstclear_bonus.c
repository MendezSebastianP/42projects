/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:24:09 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/14 12:01:40 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*currentPtr;
	t_list	*nextPtr;
	
	if (lst == NULL || del == NULL)
		return;
	else
	{
		currentPtr = *lst;
		while (currentPtr != NULL)
		{
			nextPtr = currentPtr->next;
			del(currentPtr->content);
			free(currentPtr);
			currentPtr = nextPtr;
		}
	}
	*lst = NULL;
}
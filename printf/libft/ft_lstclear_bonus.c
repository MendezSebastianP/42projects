/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:24:09 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/20 10:20:01 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:27:53 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/13 18:03:34 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *currentPtr;

	if (!lst || !new)
        	return;
	currentPtr = *lst;
	new->next = NULL;
	if (*lst == NULL)
	{
        	*lst = new;
		return;
	}
	while (currentPtr->next != NULL)
	{
		currentPtr = currentPtr->next;
	}
	currentPtr->next = new;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:03:51 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/14 12:50:09 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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

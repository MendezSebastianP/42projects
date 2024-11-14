/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:05:14 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/14 16:23:21 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>


t_list	*ft_lstlast(t_list *lst)
{
	t_list *currentPtr;

	if (lst == NULL)
        	return (NULL);
	currentPtr = lst;
	while(currentPtr->next != NULL)
		currentPtr = currentPtr->next;
	return(currentPtr);
}
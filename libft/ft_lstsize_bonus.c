/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:43:00 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/13 15:54:47 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	t_list *currentPtr;
	
	currentPtr = lst;
	while(currentPtr != NULL)
	{
		currentPtr = currentPtr->next;
		i++;
	}
	return (i);
}
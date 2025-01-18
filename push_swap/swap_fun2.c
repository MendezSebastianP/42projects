/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fun2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:52:36 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/18 11:15:04 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rot(t_list **list)
{
	t_list	*last;
	t_list	*temp;
	int		i;
	int		k;

	k = 0;
	i = ft_lstsize(*list) - 1;
	last = ft_lstlast(*list);
	ft_lstadd_front(list, last);
	*list = last;
	temp = *list;
	while (k != i)
	{
		temp = temp->next;
		k++;
	}
	temp->next = NULL;
}

void	rrr(t_list **list_a, t_list **list_b)
{
	if (!list_a || !*list_a || !list_b || !*list_b)
		return ;
	r_rot(list_a);
	r_rot(list_b);
}

/* int	main(int argc, char *argv[])
{
	// print_single(argv, r_rot);
	print_both(argv, argv + 4, rrr);
	return (0);
} */

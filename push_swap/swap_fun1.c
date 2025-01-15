/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fun1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:52:17 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/15 16:58:09 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sswap(t_list **list)
{
	t_list	*first;
	t_list	*second;

	if (!list || !*list || !(*list)->next)
		return ;
	first = *list;
	second = (*list)->next;
	first->next = second->next;
	second->next = first;
	*list = second;
}

void	ss(t_list **list_a, t_list **list_b)
{
	if (!list_a || !*list_a || !(*list_a)->next
		|| !list_b || !*list_b || !(*list_b)->next)
		return ;
	sswap(list_a);
	sswap(list_b);
}

void	spush(t_list **list_a, t_list **list_b)
{
	t_list	*first_a;
	t_list	*second_a;
	int		rule;

	rule = 0;
	if (!list_a || !*list_a)
		return ;
	if (ft_lstsize(*list_b) < 1)
		rule = 1;
	first_a = *list_a;
	second_a = (*list_a)->next;
	ft_lstadd_front(list_b, first_a);
	*list_a = second_a;
	if (rule == 1)
		first_a->next = NULL;
}

void	rotate(t_list **list)
{
	t_list	*temp;
	t_list	*node;

	temp = *list;
	node = (*list)->next;
	ft_lstadd_back(list, temp);
	*list = node;
	temp->next = NULL;
}

void	rr(t_list **list_a, t_list **list_b)
{
	if (!list_a || !*list_a || !list_b || !*list_b)
		return ;
	rotate(list_a);
	rotate(list_b);
}

/* int	main(int argc, char *argv[])
{
	print_single(argv, rotate);
	//print_both(argv, argv + 4, rr);
	return (0);
} */

// int	main(int argc, char *argv[])
// {
// 	t_list 	*b1;
// 	t_list	*b1a;
// 	int	i = 1;

// 	b1 = ptr_to_list(argv);
// 	b1a = ptr_to_list(argv + 2);
// 	while (b1 != NULL )
// 	{
// 		ft_printf("%d- ", i++);
// 		if (b1)
// 		{
// 			ft_printf("|__%s__|", b1->content);
// 			b1 = b1->next;
// 		}
// 		if (b1a != NULL)
// 		{
// 			ft_printf("|__%s__|", b1a->content);
// 			b1a = b1a->next;
// 		}
// 		ft_printf("\n");
// 	}
// 	return (0);
// }

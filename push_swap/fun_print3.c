/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_print3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:34:00 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/18 11:13:54 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Print a single stack from a linked list (t_list).
 *
 *
 * @param b1 The linked list with the numbers from the stack.
 * @return (void).
 */
void	print_s1(t_list *b1)
{
	int		i;

	i = 1;
	ft_printf("   |T     | \n");
	while (b1 != NULL)
	{
		ft_printf("%d- |__%d___| \n", i++, *(int *)b1->content);
		b1 = b1->next;
	}
}

/**
 * @brief Print both stacks, even if one is longuer than the other.
 *
 *
 * @param b1 Stack A (single simple linked list).
 * @param b2 Stack B (single simple linked list).
 * @return (void).
 */
void	print_s2(t_list *b1, t_list *b2)
{
	int		i;

	i = 1;
	ft_printf("   |T     | \n");
	while (b1 != NULL || b2 != NULL)
	{
		if (b1 != NULL)
			ft_printf("|__%d___|", *(int *)b1->content);
		if (b2 != NULL)
		{
			if (b1 == NULL)
				ft_printf("|______|");
			ft_printf("|__%d___|", *(int *)b2->content);
			b2 = b2->next;
		}
		if (b1 != NULL)
		{
			b1 = b1->next;
		}
		ft_printf("\n");
		i++;
	}
}

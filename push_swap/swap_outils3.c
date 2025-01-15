/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_outils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:43:05 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/15 17:00:22 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Pushes the smallest number to the second stack.
 *
 * This function handles pushing the smallest element from stack b1 to stack b2.
 *
 * @param b1 Pointer to the first stack.
 * @param b2 Pointer to the second stack.
 * @param index The index of the element to push.
 */
void	short_push(t_list **b1, t_list **b2, int index)
{
	int	pos_b1;
	int	pos_b2;

	pos_b1 = place_stack(b1, index);
	pos_b2 = place_maximum(b2);
	move_step(b1, b2, pos_b1, pos_b2);
}

/**
 * @brief Pushes a number to the second stack.
 *
 * This function handles pushing an element from stack b1 to stack b2
 * that is not the smallest.
 *
 * @param b1 Pointer to the first stack.
 * @param b2 Pointer to the second stack.
 * @param index The index of the element to push.
 */
void	big_push(t_list **b1, t_list **b2, int index)
{
	int	index_b2;
	int	pos_b1;
	int	pos_b2;
	int	b1content;

	b1content = content_list(*b1, index);
	index_b2 = index_closet(b1content, *b2);
	pos_b1 = place_stack(b1, index);
	pos_b2 = place_stack(b2, index_b2);
	if (pos_b1 == 1 && pos_b2 == 0 && index - index_b2 < ft_lstsize(*b1)
		- index)
		pos_b1 = 0;
	if (pos_b1 == 0 && pos_b2 == 1 && index_b2 - index < ft_lstsize(*b2)
		- index_b2)
		pos_b2 = 0;
	move_step(b1, b2, pos_b1, pos_b2);
}

/**
 * @brief Moves an element from stack b1 to the appropriate position in
 * stack b2.
 *
 * This function decides whether to perform a short push or a big push
 * based on the destination index.
 *
 * @param b1 Pointer to the first stack.
 * @param b2 Pointer to the second stack.
 * @param index The index of the element to move.
 */
void	move(t_list **b1, t_list **b2, int index)
{
	int	dest_index;
	int	p;

	p = content_list(*b1, index);
	dest_index = index_closet(p, *b2);
	if (dest_index == -2)
		short_push(b1, b2, index);
	else
	{
		big_push(b1, b2, index);
	}
}

/**
 * @brief Chooses the best move to perform based on the number of
 * required moves.
 *
 * This function calculates the number of moves needed for each element
 * in stack b1 and selects the one with the least moves to perform.
 *
 * @param b1 Pointer to the first stack.
 * @param b2 Pointer to the second stack.
 */
void	algo_badass(t_list **b1, t_list **b2)
{
	int	*nmoves;
	int	i;
	int	lenb1;

	i = 0;
	nmoves = n_moves(*b1);
	if (!nmoves || nmoves == 0)
		return ;
	lenb1 = ft_lstsize(*b1);
	while (i < lenb1)
	{
		nmoves[i] = count_moves(b1, b2, i) + 1;
		i++;
	}
	i = index_min(nmoves);
	move(b1, b2, i);
	free(nmoves);
}

/**
 * @brief Checks if the stack is sorted in ascending order.
 * This function verifies whether all elements in stack b1 are in the
 * correct order.
 *
 * @param b1 The first stack.
 * @return int 1 if sorted, 0 otherwise.
 */
int	test_isok(t_list *b1)
{
	if (b1->next == NULL)
		return (0);
	while (b1->next)
	{
		if (*(int *)b1->content > *(int *)b1->next->content)
			return (0);
		b1 = b1->next;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_outils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:43:05 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/15 16:57:06 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the index of the closest smaller element in the list.
 *
 * This function searches the linked list for the element closest to a given
 * value (`b1`) but smaller than it. If no such element exists, it returns the
 * index of the largest element in the list.
 *
 * @param b1 The reference value to compare elements against.
 * @param b2 Pointer to the head of the linked list to search within.
 * @return The index of the closest smaller element, or the index of the largest
 *         element if no smaller element is found.
 */
int	index_closet(int b1, t_list *b2)
{
	int		i;
	int		j;
	int		k;
	t_list	*start;

	i = 0;
	k = 2147483647;
	j = -2;
	start = b2;
	while (b2 != NULL)
	{
		if (*(int *)b2->content < b1 && b1 - *(int *)b2->content < k)
		{
			j = i;
			k = b1 - *(int *)b2->content;
		}
		i++;
		b2 = b2->next;
	}
	if (j == -2)
		j = index_lst_max(start);
	return (j);
}

/**
 * @brief Performs a move based on the positions of two stacks.
 *
 * Depending on the values of `a` and `b`, this function executes one of several
 * stack operations (e.g., rotate, reverse rotate,
		push) and prints the corresponding
 * action. It handles combined moves when possible.
 * 
 * - 1 value means that the node is in the second hafl of the stack.
 * 
 * - 0 value means that the node is in the first hafl of the stack.
 * 
 * - 2 value means that the node is in the perfect half of the stack
 *  (odd numbers).
 * 
 * - -1 value means that the node is in the index 0.
 *
 * @param b1 Pointer to Stack A.
 * @param b2 Pointer to Stack B.
 * @param a Move indicator for Stack A.
 * @param b Move indicator for Stack B.
 *           
 * @return 0 on successful move execution, or -1 if the move is not recognized.
 */
int	move_step(t_list **b1, t_list **b2, int a, int b)
{
	if (a != 1 && b != 1 && a != -1 && b != -1)
		return (rr(b1, b2), ft_printf("rr\n"));
	if ((a == 1 && b == 1) || (a == 1 && b == 2) || (a == 2 && b == 1))
		return (rrr(b1, b2), ft_printf("rrr\n"));
	if ((a == 0 && b == 1) || (a == 0 && b == -1) || (a == 2 && b == -1))
		return (rotate(b1), ft_printf("ra\n"));
	if ((a == -1 && b == 0) || (a == -1 && b == 2))
		return (rotate(b2), ft_printf("rb\n"));
	if ((a == 1 && b == 0) || (a == 1 && b == -1))
		return (r_rot(b1), ft_printf("rra\n"));
	if (a == -1 && b == 1)
		return (r_rot(b2), ft_printf("rrb\n"));
	if (a == -1 && b == -1)
		return (spush(b1, b2), ft_printf("pb\n"));
	return (-1);
}

/**
 * @brief Calculates the number of moves needed to complete an operation.
 *
 * This function determines the total number of moves required to perform a
 * specific operation based on the positions of elements in Stack A and
 * Stack B. It considers both forward and reverse rotations to find the most
 * efficient path.
 *
 * @param b1 Pointer to Stack A.
 * @param b2 Pointer to Stack B.
 * @param index The index in Stack A for which moves are being calculated.
 * @return The total number of moves required.
 */
int	count_moves(t_list **b1, t_list **b2, int index)
{
	int	b1content;
	int	b1len;
	int	b2len;
	int	mv1;
	int	mv2;

	b1content = content_list(*b1, index);
	b1len = ft_lstsize(*b1);
	b2len = ft_lstsize(*b2);
	mv1 = index;
	if (b1len / 2 < index)
		mv1 = index - b1len;
	mv2 = index_closet(b1content, *b2);
	if (b2len / 2 < mv2)
		mv2 = mv2 - b2len;
	if (mv1 > 0 && mv2 > 0)
		return (((mv1 >= mv2) * mv1) + ((mv1 < mv2) * mv2));
	if (mv1 < 0 && mv2 < 0)
		return (-1 * (((mv1 <= mv2) * mv1) + ((mv1 > mv2) * mv2)));
	return (ft_abs(mv1) + ft_abs(mv2));
}

/**
 * @brief Determines the position of an element in the stack.
 *
 * This function checks if the given index is in the first half or the 
 * second half of the stack. It returns:
 * - -1 if the index is 0
 * - 0 if it's in the first half
 * - 1 if it's in the second half
 * - 2 if it's exactly in the middle of an odd-sized stack
 *
 * @param b1 Pointer to the first stack.
 * @param index The index of the element.
 * @return int Position indicator.
 */
int	place_stack(t_list **b1, int index)
{
	int	a;
	int	size_b1;

	size_b1 = ft_lstsize(*b1);
	a = (size_b1 / 2 < index);
	if (size_b1 % 2 == 1 && size_b1 / 2 == index)
		a = 2;
	if (index == 0)
		return (-1);
	return (a);
}

/**
 * @brief Finds the position of the maximum element in the stack.
 *
 * This function locates the index of the largest element in stack b2
 * and determines its position relative to the middle of the stack.
 *
 * @param b2 Pointer to the second stack.
 * @return int Position indicator of the maximum element.
 */
int	place_maximum(t_list **b2)
{
	int	b;
	int	size_b2;
	int	index_max;

	size_b2 = ft_lstsize(*b2);
	index_max = index_lst_max(*b2);
	b = (size_b2 / 2 > content_list(*b2, index_max));
	if (size_b2 % 2 == 1 && size_b2 / 2 == index_max)
		b = 2;
	if (index_max == 0)
		return (-1);
	return (b);
}

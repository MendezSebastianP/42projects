/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_outils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:43:05 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/15 16:44:56 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int a)
{
	if (a >= 0)
		return (a);
	else
		return (a * -1);
}

// show the content from a node in an i index
/**
 * @brief It takes the content from the node in the choosen index.
 *
 *
 * @param b1 Stack A (single simple linked list).
 * @param index The place of the node in a single simple linked list. 0
 * is the first node, 1 the second...
 * @return An integer.
 */
int	content_list(t_list *b1, int index)
{
	int		i;
	t_list	*current;

	i = 0;
	if (b1 == NULL)
		return (0);
	if (index == -1)
	{
		current = ft_lstlast(b1);
		return (*(int *)current->content);
	}
	if (ft_lstsize(b1) < index)
		return (0);
	current = b1;
	while (i < index)
	{
		current = current->next;
		i++;
	}
	return (*(int *)current->content);
}

/**
 * @brief Allocates an integer array with the same size as the linked list.
 *
 * This function creates a dynamically allocated array of integers with a length

	* equal to the number of nodes in the linked list. The last element is set to 0.
 *
 * @param b1 The linked list.
 * @return A pointer to the integer array, or NULL if allocation fails.
 */
int	*n_moves(t_list *b1)
{
	int	i;
	int	*n1;

	i = ft_lstsize(b1);
	n1 = malloc((i + 1) * sizeof(int));
	if (!n1)
		return (0);
	n1[i] = 0;
	return (n1);
}

/**
 * @brief Finds the index of the smallest value in an integer array.
 *
 * This function searches through the array to find the index of the smallest
 * integer. If the array is NULL, it returns -1.
 *
 * @param nmoves The array of integers.
 * @return The index of the smallest value, or -1 if the array is NULL.
 */
int	index_min(int *nmoves)
{
	int	smallest;
	int	smallest_index;
	int	i;

	if (!nmoves)
		return (-1);
	if (!nmoves)
		return (-1);
	smallest = nmoves[0];
	smallest_index = 0;
	i = 0;
	while (nmoves[i])
	{
		if (nmoves[i] < smallest)
		{
			smallest = nmoves[i];
			smallest_index = i;
		}
		i++;
	}
	return (smallest_index);
}

/**
 * @brief Finds the index of the largest value in a linked list.
 *
 * This function traverses the linked list to identify the node with the largest
 * integer value and returns its index. If the list is empty, it returns -1.
 *
 * @param nmoves The linked list.
 * @return The index of the largest value, or -1 if the list is NULL.
 */
int	index_lst_max(t_list *nmoves)
{
	int		biggest;
	int		biggest_index;
	int		current_index;
	t_list	*current;

	if (!nmoves)
		return (-1);
	biggest = *(int *)nmoves->content;
	biggest_index = 0;
	current = nmoves;
	current_index = 0;
	while (current)
	{
		if (*(int *)current->content > biggest)
		{
			biggest = *(int *)current->content;
			biggest_index = current_index;
		}
		current = current->next;
		current_index++;
	}
	return (biggest_index);
}

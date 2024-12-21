/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:50:45 by smendez-          #+#    #+#             */
/*   Updated: 2024/12/21 18:38:53 by smendez-         ###   ########.fr       */
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
	int	i;
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
	if (!nmoves)
		return -1;
	int smallest;
	int smallest_index;
	int i;
	
	if (!nmoves)
		return -1;
	smallest = nmoves[0];
	smallest_index = 0;
	i = 0;
	while (nmoves[i]) {
		if (nmoves[i] < smallest) 
		{
			smallest = nmoves[i];
			smallest_index = i;
		}
	i++;
	}
	return smallest_index;
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
int index_lst_max(t_list *nmoves) 
{
    if (!nmoves)
        return -1;

    int biggest;
    int biggest_index;
    int current_index;
    t_list *current;
    
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
    return biggest_index;
}


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
	int i;
	int j;
	int k;
	t_list *start;

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
 * stack operations (e.g., rotate, reverse rotate, push) and prints the corresponding
 * action. It handles combined moves when possible.
 * 
 * - 1 value means that the node is in the second hafl of the stack.
 * 
 * - 0 value means that the node is in the first hafl of the stack.
 * 
 * - 2 value means that the node is in the perfect half of the stack (odd numbers).
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
		return(rr(b1, b2), ft_printf("rr\n"));
	if ((a == 1 && b == 1) || (a == 1 && b == 2) || (a == 2 && b == 1)) //rrr
		return(rrr(b1, b2), ft_printf("rrr\n"));
	if ((a == 0 && b == 1) || (a == 0 && b == -1) || (a ==2 && b == -1)) // ra
		return(rotate(b1), ft_printf("ra\n"));
	if ((a == -1 && b == 0) || (a == -1 && b == 2)) //rb
		return(rotate(b2), ft_printf("rb\n"));
	if ((a == 1 && b == 0) || (a == 1 && b == -1)) //rra
		return(r_rot(b1), ft_printf("rra\n"));
	if (a == -1 && b == 1)
		return(r_rot(b2),  ft_printf("rrb\n")); //rrb
	if (a == -1 && b == -1) // pa
		return(spush(b1, b2), ft_printf("pb\n"));
	return (-1);
}


/**
 * @brief Calculates the number of moves needed to complete an operation.
 *
 * This function determines the total number of moves required to perform a specific
 * operation based on the positions of elements in Stack A and Stack B. It considers
 * both forward and reverse rotations to find the most efficient path.
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
	int	mvb1;
	int	mvb2;

	b1content = content_list(*b1, index);
	b1len = ft_lstsize(*b1);
	b2len = ft_lstsize(*b2);
	mvb1 = index;
	if (b1len / 2 < index)
		mvb1 = index - b1len;
	mvb2 = index_closet(b1content, *b2);
	//printf("index closet: %d\n", mvb2);
	if (b2len / 2 < mvb2) // WE NEED TO ADD WHEN mvb2 == 2 because you can use either rrr or rr
		mvb2 = mvb2 - b2len;
	// ft_printf("%d | mvb1 = %d |||| mvb2 = %d\n", content_list(*b1, index), mvb1, mvb2);
	if (mvb1 > 0 && mvb2 > 0)
		return (((mvb1 >= mvb2) * mvb1) + ((mvb1 < mvb2) * mvb2)); // we keep the biggest
	if (mvb1 < 0 && mvb2 < 0)
		return (-1 * (((mvb1 <= mvb2) * mvb1) + ((mvb1 > mvb2) * mvb2)));
	return (ft_abs(mvb1) + ft_abs(mvb2)); // we sum both the abs value
}

/**
 * @brief Determines the position of an element in the stack.
 *
 * This function checks if the given index is in the first half or the second half
 * of the stack. It returns:
 * - -1 if the index is 0
 * - 0 if it's in the first half
 * - 1 if it's in the second half
 * - 2 if it's exactly in the middle of an odd-sized stack
 *
 * @param b1 Pointer to the first stack.
 * @param index The index of the element.
 * @return int Position indicator.
 */
int	place_stack(t_list **b1, int index) // give the place in the stack
{
	int	a;
	int	size_b1;

	size_b1 = ft_lstsize(*b1);
	// a = (size_b1 / 2 > content_list(*b1, index));
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
 * This function locates the index of the largest element in stack b2 and determines
 * its position relative to the middle of the stack.
 *
 * @param b2 Pointer to the second stack.
 * @return int Position indicator of the maximum element.
 */
int	place_maximum(t_list **b2) // give the place in the stack for the maxumum
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

/**
 * @brief Pushes the smallest number to the second stack.
 *
 * This function handles pushing the smallest element from stack b1 to stack b2.
 *
 * @param b1 Pointer to the first stack.
 * @param b2 Pointer to the second stack.
 * @param index The index of the element to push.
 */
void short_push(t_list **b1, t_list **b2, int index)
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
 * This function handles pushing an element from stack b1 to stack b2 that is not the smallest.
 *
 * @param b1 Pointer to the first stack.
 * @param b2 Pointer to the second stack.
 * @param index The index of the element to push.
 */
void big_push(t_list **b1, t_list **b2, int index)
{
	int	index_b2;
	int	pos_b1;
	int	pos_b2;
	int	b1content;

	b1content = content_list(*b1, index);
	index_b2 = index_closet(b1content, *b2);
	pos_b1 = place_stack(b1, index);
	pos_b2 = place_stack(b2, index_b2);
	if (pos_b1 == 1 &&  pos_b2 == 0 && index - index_b2 < ft_lstsize(*b1) - index)
		pos_b1 = 0;
	if (pos_b1 == 0 &&  pos_b2 == 1 && index_b2 - index < ft_lstsize(*b2) - index_b2)
		pos_b2 = 0;
	move_step(b1, b2, pos_b1, pos_b2);
}

/**
 * @brief Moves an element from stack b1 to the appropriate position in stack b2.
 *
 * This function decides whether to perform a short push or a big push based on the
 * destination index.
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
 * @brief Chooses the best move to perform based on the number of required moves.
 *
 * This function calculates the number of moves needed for each element in stack b1
 * and selects the one with the least moves to perform.
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
	nmoves = n_moves(*b1); // malloc
	if (!nmoves || nmoves == 0)
		return ;
	lenb1 = ft_lstsize(*b1);
	while (i < lenb1)
	{
		nmoves[i] = count_moves(b1, b2, i) + 1;
		i++;
	}
	// int j = 0;
	// while (j < lenb1)
	// 	// {
	// 	// 	ft_printf("%d-%d --- %d\n", j, content_list(*b1, j), nmoves[j]);
	// 	// 	j++;
	// 	// }
	i = index_min(nmoves);
	move(b1, b2, i);
	free(nmoves);
}

/**
 * @brief Checks if the stack is sorted in ascending order.
 *
 * This function verifies whether all elements in stack b1 are in the correct order.
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
			return(0);
		b1 = b1->next;
	}
	return (1);
}

/**
 * @brief Sorts the last three elements in the stack.
 *
 * This function specifically handles sorting when there are only three elements left
 * in stack b1 using swaps and rotations.
 *
 * @param list Pointer to the stack.
 * @return int -1 if already sorted, 0 otherwise.
 */
int sort_3last(t_list **list)
{
	int first;
	int second;
	int last;

	if (!list || !(*list) || !(*list)->next || !(*list)->next->next ||
	test_isok(*list) == 1)
        	return (-1);

	first = *(int *)(*list)->content;
	second = *(int *)(*list)->next->content;
	last = *(int *)(*list)->next->next->content;
	if (first < second && second > last && first > last)
		return(r_rot(list),  ft_printf("rra\n"));
	if (first > second && second > last)
		return(sswap(list), ft_printf("sa\n"), r_rot(list), ft_printf("rra\n"));
	if (first < second && second > last && first < last)
		return(sswap(list), ft_printf("sa\n"), rotate(list), ft_printf("ra\n"));
	if (first > second && second < last && first < last)
		return(sswap(list),  ft_printf("sa\n"));
	if (first > second && second < last && first > last)
		return(rotate(list),  ft_printf("ra\n"));
	return (0);
}

/**
 * @brief Finalizes the sorting by moving all elements back to stack b1.
 *
 * This function ensures that all elements are correctly placed in stack b1 by
 * performing the necessary push and rotate operations.
 *
 * @param b1 Pointer to the first stack.
 * @param b2 Pointer to the second stack.
 */
void last_please(t_list **b1, t_list **b2)
{
	int content_a;
	int content_b;
	int content_c;
	if (*(int*)(ft_lstlast(*b2)->content) > *(int *)(*b2)->content)
		(r_rot(b2), ft_printf("rrb\n"));
	while (ft_lstsize(*b2) > 0)
	{
		content_a = *(int *)(*b1)->content;
		content_b = *(int *)(*b2)->content;
		content_c = *(int*)(ft_lstlast(*b1)->content);
		if ((content_a > content_b && content_b > content_c) ||
		(test_isok (*b1) == 1 && content_b < content_a) ||
		(test_isok (*b1) == 1 && content_b > content_c))
			(spush(b2, b1), ft_printf("pa\n"));
		else
			(r_rot(b1), ft_printf("rra\n"));
	}
	if (*(int *)(*b1)->content > *(int*)(ft_lstlast(*b1)->content))
		(rotate(b1), ft_printf("ra\n"));
	// if (ft_lstsize(*b1) / 2 >= index_lst_max(*b1))
	// {
	while (test_isok(*b1) == 0 && ft_lstsize(*b1) / 2 >= index_lst_max(*b1))
			(rotate(b1), ft_printf("ra\n"));
	//}
	while (test_isok(*b1) == 0)
		(r_rot(b1), ft_printf("rra\n"));
}

/**
 * @brief The main function to execute the push_swap algorithm.
 *
 * This function initializes the stacks, checks for errors, and performs the sorting
 * using various helper functions. It also handles memory cleanup.
 *
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return int Exit status.
 */
#include <stdio.h>
int	push_swap(int argc, char **argv)
{
	t_list	*b1;
	t_list	*b2;

	b1 = ptr_to_numblist(argv);
	b2 = NULL;
	// print_s1(b1);
	if (swap_iserror(argc, argv) == 1)
		return (free_list(b1), ft_printf("Error\n"));
	if (ft_lstsize(b1) > 3)
		(spush(&b1, &b2), ft_printf("pb\n"));
	if (ft_lstsize(b1) > 3)
		(spush(&b1, &b2), ft_printf("pb\n"));
	while (ft_lstsize(b1) > 3)
		(algo_badass(&b1, &b2)/* , print_s2(b1, b2) */);
	sort_3last(&b1);
	if (b2)
		last_please(&b1, &b2);
	free_list(b1);
	free_list(b2);
	return (0);
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	push_swap(argc, argv);
	return (0);
}

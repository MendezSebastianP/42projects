/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:50:45 by smendez-          #+#    #+#             */
/*   Updated: 2024/12/18 13:58:03 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	content_list(t_list *b1, int index) // show the content from an i index
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

int	*n_moves(t_list *b1) // create a empty malloc with n elements
{
	int	i;
	int	*n1;

	i = ft_lstsize(b1);
	n1 = malloc(i * sizeof(int) + 1);
	if (!n1)
		return (0);
	n1[i + 1] = 0;
	return (n1);
}

// search in the previous malloc the smallest index
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

// will search in a linked list the index from the biggest value
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

/* int	count_moves(t_list *b1, t_list *b2)
{
		
} */

/**
 * @brief Finds the index of the element in the list that is closest to a given value, 
 *        considering only elements smaller than the given value.
 *
 *
 * @param b1 The reference value to compare elements against.
 * @param b2 Pointer to the head of the linked list (t_list) to search within.
 * @return The index of the closest element in the list smaller than `b1`, or
 *         the index of the largest element in the list if no such element exists.
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
int	pos_list(t_list **b1, t_list **b2, int index) // 
{
	int	a;
	int	b;
	int	size_b1;
	int	size_b2;
	int	index_max;

	size_b1 = ft_lstsize(*b1);
	size_b2 = ft_lstsize(*b2);
	index_max = index_lst_max(b2);
	a = (size_b1 / 2 > content_list(*b1, index)) * 2;
	if (size_b1 % 2 == 1 && size_b1 / 2 == index)
		a = 4;
	b = (size_b2 / 2 > content_list(*b2, index)) ;
	if (size_b2 % 2 == 1 && size_b2 / 2 == index)
		b = 6;
	if (index + index_max == 0)
		return (11);
	return (a + b);
}


void short_push(t_list **b1, t_list **b2, int index)
{
	int	index_max;

	index_max = index_lst_max(b2);
	
	
}


void	move(t_list **b1, t_list **b2, int index)
{
	int	dest_index;
	int	p;
	
	p = content_list(*b1, index);
	dest_index = index_closet(p, *b2);
	if (dest_index == -2)
		short_push(b1, b2, index);
}

/* void move(t_list **b1, t_list **b2, int index)
{
	int	i;
	int	j;
	int	n;

	j = 0;
	i = 0;
	n = ft_lstsize(b1);
	if (n / 2 < index)
	{
		while()
	}
	while (i < index)
	{
		b1 =(*b1)->next;
		i++;
	}
	while ()
} */

/* void	algo1(t_list *b1, t_list *b2)
{
	int	*nmoves;
	int	ind;
	int	i;

	nmoves = n_moves(b1);
	i = 0;
	while (b1[i])
	{
		
	}
} */

#include <stdio.h>
int	main(int argc, char *argv[])
{
	int i = 0;
	t_list *b1 = ptr_to_numblist(argv);
	// int *k1 = n_moves(b1);
	// k1[0] = 1;
	// k1[1] = 7;
	// k1[2] = 5;
	// k1[3] = 2;
	// k1[4] = 4;
	// while(k1[i])
	// 	ft_printf("%d\n", k1[i++]);
	printf("index min: %d\n", index_closet(3, b1));
	// free(k1);
	return (0);
}

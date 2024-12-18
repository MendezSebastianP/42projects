/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:50:45 by smendez-          #+#    #+#             */
/*   Updated: 2024/12/18 19:30:05 by smendez-         ###   ########.fr       */
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

// according the position of b1 and b2 it will action one step foward in the moves
int	move_step(t_list **b1, t_list **b2, int a, int b) 
{
	if (a != 1 && b != 1 && a != -1 && b != -1) //rr (a = 0 && b = 0 || a = 0 && b = 2 || a = 2 && b = 0 || a = 2 && b = 2)
		return(rr(b1, b2), ft_printf("rr\n"));
	if (a == 1 && b == 1 || a == 1 && b == 2 || a == 2 && b == 1) //rrr
		return(rrr(b1, b2), ft_printf("rr\n"));
	if (a == 0 && b == 1 || a == 0 && b == -1 || a ==2 && b == -1) // ra
		return(rotate(b1), ft_printf("ra\n"));
	if (a == -1 && b == 0 || a == -1 && b == 2) //rb
		return(rotate(b2), ft_printf("rb\n"));
	if (a == 1 && b == 0 || a == 1 && b == -1) //rra
		return(r_rot(b1), ft_printf("rra\n"));
	if (a == -1 && b == 1)
		return(r_rot(b1), ft_printf("rrb\n"));
	if (a == -1 && b == -1) // pa
		return(spush(b1, b2), ft_printf("pa\n"));
	return (-1);
}

// count how many moves until done
int	count_moves(t_list **b1, t_list **b2, int index)
{
	int	closest_b2;
	int	b1content;
	int	b1len;
	int	b2len;
	int	mvb1;
	int	mvb2;

	b1content = content_list(*b1, index);
	closest_b2 = index_closet(b1content, *b2);
	b1len = ft_lstsize(*b1);
	b2len = ft_lstsize(*b2);
	mvb1 = index;
	if (b1len / 2 < index)
		mvb1 = index - b1len;
	mvb2 = index_closet(b1content, *b2);
	if (b2len / 2 < index)
		mvb2 = index - b2len;
	if (mvb1 > 0 && mvb2 > 0)
		return (((mvb1 > mvb2) * mvb1) + ((mvb1 < mvb2) * mvb2)); // we keep the biggest
	if (mvb1 < 0 && mvb2 < 0)
		return (-1 * (((mvb1 > mvb2) * mvb1) + ((mvb1 < mvb2) * mvb2))); // we keep the biggest
	return (-1);
}

int	place_stack(t_list **b1, int index) // give the place in the stack
{
	int	a;
	int	size_b1;

	size_b1 = ft_lstsize(*b1);
	a = (size_b1 / 2 > content_list(*b1, index));
	if (size_b1 % 2 == 1 && size_b1 / 2 == index)
		a = 2;
	if (index == 0)
		return (-1);
	return (a);
}

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


void short_push(t_list **b1, t_list **b2, int index)
{
	int	index_max;
	int	pos_b1;
	int	pos_b2;

	pos_b1 = place_stack(b1, index);
	pos_b2 = place_maximum(b2);
	move_step(b1, b2, pos_b1, pos_b2);
}



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
	move_step(b1, b2, pos_b1, pos_b2);
}

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

void	algo_badass(t_list **b1, t_list **b2)
{
	int	*nmoves;
	int	i;
	int	lenb1;

	i = 0;
	nmoves = n_moves(*b1); // malloc
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

void sort_3last(t_list **list)
{
	int first;
	int second;
	int last;

	first = *(int *)(*list)->content;
	second = *(int *)(*list)->next->content;
	last = *(int *)(*list)->next->next->content;

	if (first < second && second > last && first > last)
		r_rot(list);
	if (first > second && second > last)
	{
		sswap(list);
		r_rot(list);
	}
	if (first < second && second > last && first < last)
	{
		sswap(list);
		rotate(list);
	}
	if (first > second && second < last && first < last)
		sswap(list);
	if (first > second && second < last && first > last)
		rotate(list);
}

void last_please(t_list **b1, t_list **b2)
{
	int content_a;
	int content_b;
	int content_c;

	while (ft_lstsize(*b2) > 0)
	{
		content_a = *(int *)(*b1)->content;
		content_b = *(int *)(*b2)->content;
		content_c = *(int*)(ft_lstlast(*b1)->content);
		if (content_a > content_b && content_b > content_c)
			spush(b2, b1);
		else
			r_rot(b1);
	}	
}

void	print_s1(t_list *b1) // delete
{

	t_list 	*b1_free;
	int	i = 1;
	b1_free = b1;
	ft_printf("   |T     | \n");
	while (b1 != NULL)
	{
		ft_printf("%d- |__%d___| \n", i++, *(int *)b1->content);
		b1 = b1->next;
	}
}

int	push_swap(int argc, char **argv)
{
	t_list	*b1;
	t_list	*b2;

	b1 = ptr_to_numblist(argv);
	b2 = NULL;
	print_s1(b1);
	if (swap_iserror(argc, argv) == 1)
		return (ft_printf("Error\n"));
	if (ft_lstsize(b1) > 3)
		spush(&b1, &b2);
	if (ft_lstsize(b1) > 3)
		spush(&b1, &b2);
	while(ft_lstsize(b1) > 3)
		algo_badass(&b1,&b2);
	sort_3last(&b1);
	if (b2)
		last_please(&b1, &b2);
	print_s1(b1);
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

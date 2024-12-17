/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:50:45 by smendez-          #+#    #+#             */
/*   Updated: 2024/12/17 17:38:08 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*n_moves(t_list *b1)
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

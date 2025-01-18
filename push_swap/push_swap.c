/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:50:45 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/18 14:40:06 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char const *s1, const char *s2)
{
	char			*t;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	t = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (t == NULL)
		return (NULL);
	while (s1[i])
	{
		t[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		t[i + j] = s2[j];
		j++;
	}
	t[i + j] = '\0';
	return (t);
}

/**
 * @brief Sorts the last three elements in the stack.
 *
 * This function specifically handles sorting when there are only three
 * elements left in stack b1 using swaps and rotations.
 *
 * @param list Pointer to the stack.
 * @return int -1 if already sorted, 0 otherwise.
 */
int	sort_3last(t_list **list)
{
	int	first;
	int	second;
	int	last;

	if (!list || !(*list) || !(*list)->next || !(*list)->next->next
		|| test_isok(*list) == 1)
		return (-1);
	first = *(int *)(*list)->content;
	second = *(int *)(*list)->next->content;
	last = *(int *)(*list)->next->next->content;
	if (first < second && second > last && first > last)
		return (r_rot(list), ft_printf("rra\n"));
	if (first > second && second > last)
		return (sswap(list), ft_printf("sa\n"), r_rot(list),
			ft_printf("rra\n"));
	if (first < second && second > last && first < last)
		return (sswap(list), ft_printf("sa\n"), rotate(list),
			ft_printf("ra\n"));
	if (first > second && second < last && first < last)
		return (sswap(list), ft_printf("sa\n"));
	if (first > second && second < last && first > last)
		return (rotate(list), ft_printf("ra\n"));
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
void	last_please(t_list **b1, t_list **b2)
{
	int	content_a;
	int	content_b;
	int	content_c;

	if (*(int *)(ft_lstlast(*b2)->content) > *(int *)(*b2)->content)
		(r_rot(b2), ft_printf("rrb\n"));
	while (ft_lstsize(*b2) > 0)
	{
		content_a = *(int *)(*b1)->content;
		content_b = *(int *)(*b2)->content;
		content_c = *(int *)(ft_lstlast(*b1)->content);
		if ((content_a > content_b && content_b > content_c)
			|| (test_isok(*b1) == 1 && content_b < content_a)
			|| (test_isok(*b1) == 1 && content_b > content_c))
			(spush(b2, b1), ft_printf("pa\n"));
		else
			(r_rot(b1), ft_printf("rra\n"));
	}
	while (test_isok(*b1) == 0 && ft_lstsize(*b1) / 2 >= index_lst_max(*b1))
		(rotate(b1), ft_printf("ra\n"));
	while (test_isok(*b1) == 0)
		(r_rot(b1), ft_printf("rra\n"));
}

/**
 * @brief The main function to execute the push_swap algorithm.
 *
 * This function initializes the stacks, checks for errors,
	and performs the sorting
 * using various helper functions. It also handles memory cleanup.
 *
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return int Exit status.
 */
int	push_swap(int argc, char **argv)
{
	t_list	*b1;
	t_list	*b2;

	if (argc == 1)
		return (0);
	b1 = ptr_to_numblist(argv);
	b2 = NULL;
	if (swap_iserror(argc, argv) == 1)
		return (free_list(b1), write(2, "Error\n", 7));
	if (argc == 3 && test_isok(b1) == 0)
		return (r_rot(&b1), free_list(b1), ft_printf("rra\n"));
	if (test_isok(b1) == 1)
		return (free_list(b1), 0);
	if (ft_lstsize(b1) > 3)
		(spush(&b1, &b2), ft_printf("pb\n"));
	if (ft_lstsize(b1) > 3)
		(spush(&b1, &b2), ft_printf("pb\n"));
	while (ft_lstsize(b1) > 3)
		(algo_badass(&b1, &b2));
	sort_3last(&b1);
	if (b2)
		last_please(&b1, &b2);
	free_list(b1);
	free_list(b2);
	return (0);
}

int	main(int argc, char *argv[])
{	
	char	**str;
	char	*temp;
	char	*space;
	int		i;

	i = 0;
	if (argc == 2)
	{
		space = ft_strjoin(" ", argv[1]);
		temp = ft_strjoin(argv[0], space);
		str = ft_split(temp, ' ');
		while (str[i])
			i++;
		if (i == 1)
			return (free(temp), free(space),
				cleanexit(str), ft_printf("Error\n"));
		push_swap(argc + i -2, str);
		(free(temp), free(space));
		cleanexit(str);
		return (0);
	}
	push_swap(argc, argv);
	return (0);
}

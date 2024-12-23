/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:39:26 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/11 16:42:50 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nitems, size_t size)
{
	unsigned char	*t;
	size_t			i;
	size_t			k;

	i = 0;
	k = nitems * size;
	t = malloc(k);
	if (t == NULL || (size != 0 && k / size != nitems))
		return (NULL);
	while (nitems * size > i)
	{
		t[i] = 0;
		i++;
	}
	return (t);
}

/* 
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	n;
	int	i;
	int	*s1;
	int	*s2;

	(void)argc;
	n = atoi(argv[1]);
	i = 0;
	s1 = (int *)ft_calloc(n, 2147483647);
	s2 = (int *)calloc(n, 2147483647);
	printf("Our result	: ");
	while (i < n)
	{
		printf("%d ", s1[i]);
		i++;
	}
	i = 0;
	printf("\n");
	printf("Intended result	: ");
	while (i < n)
	{
		printf("%d ", s2[i]);
		i++;
	}
	printf("\n");
	free(s1);
	free(s2);
	return (0);
}

 */
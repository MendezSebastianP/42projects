/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:04 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/15 10:04:57 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	c2;

	ptr = (unsigned char *)str;
	i = 0;
	c2 = (unsigned char)c;
	if (n == 0)
		return (NULL);
	while (ptr[i] != c2 && i != n)
		i++;
	if (ptr[i] == c2)
		return ((void *)(ptr + i));
	else
		return (NULL);
}

/* 
#include <stdio.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	char	*l1;
	char	*l2;

	(void)argc;
	l1 = ft_memchr(argv[1], argv[2][0], strlen(argv[1]));
	l2 = memchr(argv[1], argv[2][0], strlen(argv[1]));
	printf("Our result	: %s \n", l1);
	printf("Intended result	: %s", l2);
	return (0);
} */
/* This function is very usefull to count how many times you find a character
or to find the index	(printf("position:%ld", result - text)) */

/* int main(int argc, char *argv[])
{
	(void)argc;
	int i = 0;
	int j = 0;
	char *a = argv[1];

	printf("The letter |%c| is found at index: %ld \n",argv[2][0], ft_memchr(a,
			argv[2][0]) - a);
	a = ft_memchr(a + 1, argv[2][0]);
	while(a != NULL)
	{
		a = ft_memchr(a + 1, argv[2][0]);
		printf("Also... letter |%c| is found at position: %ld \n",argv[2][0],
			ft_memchr(a, argv[2][0]) - argv[1]);
	}
	return (0);
} */
/* 
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	char *t2 = ft_memchr(s, 0, 1);
	char *t5 = ft_memchr(s, 2 + 256, 3);
	char *t2b = memchr(s, 0, 1);
	char *t5b = memchr(s, 2 + 256, 3);
	printf("%d %s\n intended result:%s\n",
	ft_memchr(s, 0, 1) == s, t2, t2b);
	printf("%d %s\n intended result:%s\n",
	ft_memchr(s, 2 + 256, 3) == s + 2, t5, t5b); 
	return (0);
}
 */
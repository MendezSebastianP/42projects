/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:42:11 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/11 14:38:32 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Needed to return NULL, if not it doesnt work :( */
/* strnstr didnt work at home, verifie at school*/
#include <stddef.h>

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnstr(const char *str, const char *search_str, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (ft_strlen(str) == 0 && ft_strlen(search_str) == 0)
		return ((char *)str);
	if (ft_strlen(str) == 0)
		return (NULL);
	while (i < n)
	{
		j = 0;
		while (str[i] != search_str[j] && str[i] != '\0')
			i++;
		if (str[i] == search_str[j])
		{
			while (str[i + j] == search_str[j] && j + i < n)
				j++;
		}
		if (ft_strlen(search_str) == j || j == n)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	(void)argc;
	printf("Our result : %s \n", ft_strnstr(argv[1], argv[2], 
			atoi(argv[3])));
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

	printf("The letter |%c| is found at index: %ld \n",argv[2][0], ft_strnstr(a,
			argv[2][0]) - a);
	a = ft_strnstr(a + 1, argv[2][0]);
	while(a != NULL)
	{
		a = ft_strnstr(a + 1, argv[2][0]);
		printf("Also... letter |%c| is found at position: %ld \n",argv[2][0],
			ft_strnstr(a, argv[2][0]) - argv[1]);
	}
	return (0);
} */

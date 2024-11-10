/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:32 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/10 14:36:43 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Test overlapping with source +2 if doenst work */
#include <stddef.h>

void	*ft_memmove(void *dest_str, const void *src_str, size_t n)
{
	size_t			i;
	char			*ptr;
	char			*src;

	if (dest_str == NULL || src_str == NULL)
		return (NULL);
	ptr = (char *)dest_str;
	src = (char *)src_str;
	if (ptr > src)
	{
		i = n;
		while (i++ > 0)
		{
			ptr[i - 1] = src[i - 1];
			i--;
		}
		return (dest_str);
	}
	i = 0;
	while (i++ < n)
	{
		ptr[i] = src[i];
		i++;
	}
	return (dest_str);
}

/* 
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}
int	main(void)
{
	char	str1[15];

	strcpy(str1, "abcde");
	memmove(str1, str1+ 2, 4);
	ft_memmove(str2 + 2, str2, 4);
	printf("Intended result	: %s \n", str1);
	printf("Our result	: %s \n", str2);
	return (0);
} */
/* int main(void)
{
	const char str[100] = "Just trying";
	char str1[21];
	char str2[21];
	strcpy(str1, "abcrrr");
	strcpy(str2, "abcrrr");
	memmove(str1, str, 2);
	ft_memmove(str2, str, 2);
	printf("Intended result: %s \n", str1);
	printf("Our result		: %s \n", str2);
	return (0);
} */

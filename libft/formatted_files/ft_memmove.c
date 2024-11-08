/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:32 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/08 18:57:22 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Test overlapping with source +2 if doenst work */
#include <stddef.h>

int	overlaptest(void *dest_str, const void *src_str, size_t n)
{
	const unsigned char	*src_start = (const unsigned char *)src_str;
	const unsigned char	*src_end = src_start + n - 1;
	const unsigned char	*dest_start = (const unsigned char *)dest_str;
	const unsigned char	*dest_end = dest_start + n - 1;

	if ((src_start <= dest_end) && (src_end >= dest_start))
		return (1);
	return (0);
}

void	*ft_memmove(void *dest_str, const void *src_str, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	const unsigned char	*src;

	if (dest_str == NULL || src_str == NULL)
		return (NULL);
	ptr = (unsigned char *)dest_str;
	src = (const unsigned char *)src_str;
	if (overlaptest(dest_str, src_str, n))
	{
		i = n;
		while (i > 0)
		{
			ptr[i - 1] = src[i - 1];
			i--;
		}
		return (dest_str);
	}
	i = 0;
	while (i < n)
	{
		ptr[i] = src[i];
		i++;
	}
	return (dest_str);
}

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
// test1 overlap
int	main(void)
{
	char	str1[15];
	char	str2[15];

	strcpy(str1, "abcd");
	strcpy(str2, "abcd");
	memmove(str1, str1+2, 4);
	ft_memmove(str2, str2+2, 4);
	printf("Intended result	: %s \n", str1);
	printf("Our result	: %s \n", str2);
	printf("\nDetailed str2 contents after ft_memmove:\n");
	for (int i = 0; i < 6; i++) {
        	printf("str2[%d]: '%c' (ASCII: %d)\n", i, str2[i] ? str2[i] : '0', str2[i]);
	}
	return (0);
}
// test 2 rest
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

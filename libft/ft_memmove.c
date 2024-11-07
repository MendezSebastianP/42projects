/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:32 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/06 09:32:44 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Test overlapping with source +2 if doenst work */
#include <stddef.h>
int overlaptest(void *dest_str, const void * src_str, size_t n)
{
	const char *src_start = src_str;
	const char *src_end = src_str + n - 1;
	const char *dest_start = dest_str;
	const char *dest_end = dest_str + n - 1;
	if((src_start <= dest_end) && (src_end >= dest_start))
		return (1);
	return (0);
}

void	*ft_memmove(void *dest_str, const void * src_str, size_t n)
{
	size_t i;
	unsigned char *ptr;
	const char *src;

	if (dest_str == NULL || src_str == NULL)
		return (NULL);
	ptr = dest_str;
	src = src_str;
	if (overlaptest(dest_str, src_str, n))
	{
		i = n;
		while (i > 0)
		{
			ptr[i-1] = src[i-1];
			i--;
		}
	return (dest_str);
	}
	else
	{
		i = 0;
		while (i < n)
		{
			ptr[i] = src[i];
			i++;
		}
		return dest_str;
	}
}

#include <string.h>
#include <stdio.h>

size_t ft_strlen(const char *c)
{
	int i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}
// test1 overlap
int main(void)
{
	char str1[21];
	char str2[21];
	strcpy(str1, "abcde");
	strcpy(str2, "abcde");
	memmove(str1 + 2, str1, 10);
	ft_memmove(str2 + 2, str2, 10);
	printf("Intended result: %s \n", str1);
	printf("Our result	 : %s \n", str2);
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
	printf("Our result	 : %s \n", str2);
	return (0);
} */

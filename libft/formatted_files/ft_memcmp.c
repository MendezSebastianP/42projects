/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:17 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/08 15:47:52 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	j;
	unsigned int	i;
	const unsigned char	*s1a;
	const unsigned char	*s2a;

	i = 0;
	j = 0;
	s1a = (const unsigned char *)s1;
	s2a = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && *s1a == *s2a)
	{
		s1a++;
		s2a++;
	}
	j = *s1a - *s2a;
	return (j);
}
/* 
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[15];
	char	str2[15];
	int		sum1;
	int		sum2;

	memcpy(str, "abcdef", 6);
	memcpy(str2, "ABCDEF", 6);
	sum1 = ft_memcmp(str, str2, 3);
	sum2 = memcmp(str, str2, 3);
	printf("our result	: %d \n", sum1);
	printf("intended result	: %d", sum2);
	return (0);
} */

/* int main () 
{
   char str1[15];
   char str2[15];
   int ret;

   memcpy(str1, "abcdef", 6);
   memcpy(str2, "ABCDEF", 6);

   ret = memcmp(str1, str2, 5);

   printf("result: %d\n", ret);
   return(0);
} */

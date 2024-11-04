/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:17 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/04 12:41:18 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> 

int     ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned int    j;
    unsigned int    i;
    const char *s1a;
    const char *s2a;
    ;
    i = 0;
    j = 0;
    s1a = s1;
    s2a = s2;
    if (n == 0)
            return (0);
    while (s1a[i] != '\0' && s1a[i] == s2a[i] && i < n - 1)
            i++;
    j = s1a[i] - s2a[i];
    return (j);
}

#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "zd7ddd";
    char str2[] = "ddd";
    int sum1;
    int sum2;

    sum1 = ft_memcmp(str, str2, 2);
    sum2 = memcmp(str, str2, 2);
    printf("our result: %d \n", sum1);
    printf("intended result: %d", sum2);
    return 0;
}

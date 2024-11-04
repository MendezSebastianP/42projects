/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:24 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/04 12:41:25 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void    *ft_memcpy(void *dest_str, const void * src_str, size_t n)
{
    size_t i;
    unsigned char *ptr;
    const char *src;

    if (dest_str == NULL || src_str == NULL)
    return (NULL);
    i = 0;
    ptr = dest_str;
    src = src_str;
    while (i < n)
    {
        ptr[i] = src[i];
        i++;
    }
    return dest_str;
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

int main(void)
{
    const char src[50] = "I hope";
    char str1[50];
    char str2[50];
    strcpy(str1, "Lets see what happen");
    strcpy(str2, "Lets see what happen");
    memcpy(str1, src, ft_strlen(src) + 1);
    ft_memcpy(str2, src, ft_strlen(src) + 1);
    printf("Intended result: %s \n", str1);
    printf("Our result     : %s", str2);
    return (0);
}
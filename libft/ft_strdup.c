/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:51 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/04 12:41:52 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_strlen(const char *c)
{
    size_t i;

    i = 0;
    while (c[i] != '\0')
        i++;
    return (i);
}

void    *ft_strdup(const char * source)
{
        unsigned char    *t;
        size_t  i;
        size_t  nitems;

        i = 0;
        nitems = ft_strlen(source);
        t = malloc(nitems * sizeof(char) + 1);
        if (t == NULL)
                return (NULL);
        while (nitems > i)
        {
                t[i] = source[i];
                i++;
        }
        t[i] = '\0';
        return (t);
}

#include <stdio.h>
#include <string.h>

int     main(int argc, char *argv[])
{
        (void)argc;
        char *str = argv[1];
        char *s1 = ft_strdup(str);;
        char *s2 = strdup(str);;
        int i = 0;

        printf("Our result     : %s\n", s1);
        printf("Intended result: %s", s2);
        free(s1);
        free(s2);
        return(0);
} 



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:38:06 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/04 12:38:45 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdlib.h>

int ft_strlen(const char *c)
{
    size_t i;

    i = 0;
    while (c[i] != '\0')
        i++;
    return (i);
}

char    *ft_strjoin(char const *s1, const char *s2)
{
        unsigned char    *t;
        size_t  i;
        size_t  j;

        i = 0;
        t = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
        if (t == NULL)
                return (NULL);
        while (s1[i])
        {
                t[i] = s1[i];
                i++;
        }
        while (s2[j])
        {
                t[i + j] = s2[j];
                j++;
        }
        t[i + j] = '\0';
        return (t);
}


#include <stdio.h>
#include <string.h>

int     main(int argc, char *argv[])
{
        (void)argc;
        char *s1 = ft_strjoin(argv[1], argv[2]);;
        /* char *s2 = substr(str, start, len); */
        printf("Our result     : %s\n", s1);
        /* printf("Intended result: %s", s2); */
        free(s1);
        /* free(s2); */
        return(0);
} 



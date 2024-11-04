/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:35:37 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/04 18:05:20 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int lent2(char const *s1, char c1, int t1)
{
    int i;
    int j;
    int k;
    
    i = 0;
    k = -1;
    while (s1[i])
    {
        j = 0;
        while (s1[i] == c1)
            i++;
        while (s1[i] != c1 && s1[i])
        {
            i++;
            j++;
        }
        if (s1[i] == c1 || !s1[i])
            k++;
        if (k == t1)
        return (j);
    }
    return (0);
}

int splitlen(char const *s1, char c1)
{
    int i;
    int j;
    int k;
    i = 0;
    j = 0;
    k = 0;
    while (s1[i])
    {
        while (s1[i] == c1 && s1[i])
        {
            i++;
            j++;
        }
        if (!s1[i])
            break;
        i++;
        k++;
    }
    return (i + k - j);
}
char    **ft_split(char const *s, char c)
{
    char    **t1;
    char    *t2;
    int k;
    int i;
    int j;

    t1 = malloc(splitlen(s,c) * sizeof(char) + 1);
    if (t1 == NULL)
        return (NULL);
    i = 0;
    j = 0;
    while(s[i])
    { 
        while(s[i] == c)
            i++;
        if (!s[i])
            break;
        t2 = malloc(lent2(s, c, j) * sizeof(char) + 1);
        k = 0;
        while(s[i] != c)
        {
            t2[k++] = s[i];
            i++;
        }
        t2[k+1] = '\0';
        t1[j++] = t2;
        i++;
    }
    t1[j+1] = "\0";
    return (t1);
}

#include <stdio.h>

int main(int c, char *v[])
{
    (void)c;
    int i;
    i = 0;
    char **a = ft_split(v[1], v[2][0]);
    while(a[i])
    {
        printf("%s\n", a[i]);
        i++;
    }
    free(a);
    return (0);
}

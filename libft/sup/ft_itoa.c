/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:42:49 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/05 13:15:04 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* il y a un problemen avec les longs int, je peux pas gerer le min,
meme dans les autres fonctions... */
#include <stdlib.h>

int	powerf(int b)
{
    int	c;

	c = 1;
	while (b > 0)
	{
		c = c * 10;
		b = b - 1;
	}
	return (c);
}
int sizenbr(int numb)
{
    int i;

    i = 1;
    if (numb < 0)
    {
        i++;
        numb = numb * -1;
    }
    if ((numb / 10) == 0)
        return (1);
    while ((numb / 10) > 0)
    {
        numb = numb / 10;
        i++;
    }
    return (i);
}

char    *ft_itoa(int k)
{
    int i;
    long int j;
    long int n;
    int sizen;
    char    *str1;

    n = k;
    i = 0;
    sizen = sizenbr(n);
    str1 = malloc(sizen * sizeof(long int));
    if (!str1)
        return (NULL);
    if (n < 0)
    {
        str1[i] = '-';
        i++;
        n = n * -1;
    }
    j = n;
    while(i < sizen)
    {
        while(j > 9)
            j = j / 10;
        str1[i] = j + 48;
        
        n = n - (j * powerf(sizen - i - 1));
        j = n;
        i++;
    }
    str1[i] = '\0';
    return(str1);
}
#include <stdlib.h>
#include <stdio.h>
int main(int c, char *v[])
{
    (void)c;
    char    *s1 = ft_itoa(atoi(v[1]));
    printf("Our function: %s", s1);
    free(s1);
    return (0);
}


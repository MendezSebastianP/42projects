/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:42:49 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/05 10:50:05 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    if ((numb / 10) == 0)
        return (1);
    while ((numb / 10) > 0)
    {
        numb = numb / 10;
        i++;
    }
    return (i);
}

char    *ft_itoa(int n)
{
    int i;
    int j;
    int sizen;
    char    *str1;

    i = 0;
    j = n;
    sizen = sizenbr(n);
    str1 = malloc(sizen * sizeof(int));
    if (!str1)
        return (NULL);
    while(j > 10)
        j = j / 10;
    str1[i] = j + 48;
    j = j * powerf(sizen - i);
    return(str1);
}


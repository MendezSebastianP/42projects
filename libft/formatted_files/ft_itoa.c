/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:42:49 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/06 10:00:06 by smendez-         ###   ########.fr       */
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
int	sizenbr(int numb)
{
	int	i;

	i = 1;
	if (numb == -2147483648)
		numb = -2147483647;
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
int	firstnumb(long int numb)
{
	while (numb > 9)
		numb = numb / 10;
	return (numb);
}

char	*ft_itoa(int k)
{
	int			i;
	long int	n;
	int			sizen;
	char		*str1;

	n = k;
	i = 0;
	sizen = sizenbr(n);
	str1 = malloc(sizen * sizeof(long int));
	if (!str1)
		return (NULL);
	if (n < 0)
	{
		str1[i++] = '-';
		n = n * -1;
	}
	while (i < sizen)
	{
		str1[i] = firstnumb(n) + 48;
		n = n - (firstnumb(n) * powerf(sizen - i++ - 1));
	}
	str1[i] = '\0';
	return (str1);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int c, char *v[])
{
	char	*s1;

	(void)c;
	s1 = ft_itoa(atoi(v[1]));
	printf("Our function: %s", s1);
	free(s1);
	return (0);
}

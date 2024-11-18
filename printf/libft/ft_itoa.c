/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:42:49 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/15 16:26:18 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	powerf(int b)
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

static int	sizenbr(long int numb)
{
	long int	i;

	i = 1;
	if (numb == -2147483648)
		numb = -2147483647;
	if (numb < 0)
	{
		i++;
		numb = numb * -1;
	}
	if ((numb / 10) == 0)
		return (i);
	while ((numb / 10) > 0)
	{
		numb = numb / 10;
		i++;
	}
	return (i);
}

static int	firstnumb(long int numb, int sizen)
{
	if (sizenbr(numb) != sizen)
		return (0);
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
	str1 = malloc(sizen * sizeof(char) + 1);
	if (!str1)
		return (NULL);
	if (n < 0)
	{
		str1[i++] = '-';
		n = n * -1;
	}
	while (i < sizen)
	{
		str1[i] = firstnumb(n, sizen - i) + 48;
		n = n - (firstnumb(n, sizen - i) * powerf(sizen - i - 1));
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

/* #include <stdio.h>
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
 */
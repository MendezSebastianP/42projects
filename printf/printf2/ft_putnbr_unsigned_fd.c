/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:27:03 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/25 16:42:59 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


static unsigned int	powerf(unsigned int b)
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

static unsigned int	sizenbr(unsigned int numb)
{
	long int	i;

	i = 1;
	if ((numb / 10) == 0)
		return (i);
	while ((numb / 10) > 0)
	{
		numb = numb / 10;
		i++;
	}
	return (i);
}

static unsigned int	firstnumb(unsigned int numb, unsigned int sizen)
{
	if (sizenbr(numb) != sizen)
		return (0);
	while (numb > 9)
		numb = numb / 10;
	return (numb);
}

static char	*ft_itoa_un(unsigned int k, char *mainmalloc)
{
	int			i;
	long int	n;
	int			sizen;

	n = k;
	i = 0;
	sizen = sizenbr(n);
	while (mainmalloc[i])
		i++;
	while (i < sizen)
	{
		mainmalloc[i] = firstnumb(n, sizen - i) + 48;
		n = n - (firstnumb(n, sizen - i) * powerf(sizen - i - 1));
		i++;
	}
	return (mainmalloc);
}

int	ft_putnbr_unsigned_fd(unsigned int k, int verbose, char *mainmalloc)
{
	int	i;
	
	if (verbose == 0)
	{
		i = ft_strlen(ft_itoa_un(k, mainmalloc));
		return (i);
	}
	i = ft_putstr_fd(ft_itoa_un(k, mainmalloc), 1);
	return (i);
}

/* #include <stdio.h>
#include <stdlib.h>

int	main(int c, char *v[])
{
	char	*s1;

	(void)c;
	int i = ft_putnbr_unsigned_fd(-1,0);
	printf("\n%d", i);
	return (0);
} */

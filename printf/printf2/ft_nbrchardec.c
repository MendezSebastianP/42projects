/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrchardec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:52:23 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/27 16:29:44 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	msize1(long int a, char *base)
{
	long int		lenb;
	long int		i;
	long int		b;

	i = 1;
	b = a;
	lenb = ft_strlen(base);
	if (a < 0)
	{
		b = -b;
		i++;
	}
	while (lenb <= b)
	{
		b = b / lenb;
		i++;
	}
	return (i);
}

static char	*motor1(long int nbr, char *base, char *final, int index)
{
	long int		size;
	long int		k;
	long int		nb;
	long int		i;

	size = ft_strlen(base);
	i = index;
	k = msize1(nbr, base) - 1;
	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
		final[i] = '-';
	}
	while (k > 0 && nb >= size)
	{
		final[k + i] = base[nb % size];
		nb = nb / size;
		k--;
	}
	final[k + i] = base[nb];
	return (final);
}

char	*ft_nbrchardec(int nbr, int unsigned1, char *mainmalloc, int index)
{
	char	*base;

	base = "0123456789";
	if (unsigned1 == 1)
	{
		mainmalloc = motor1((unsigned int)nbr, base, mainmalloc, index);
		return (mainmalloc);
	}
	mainmalloc = motor1(nbr, base, mainmalloc, index);
	return (mainmalloc);
}

/* #include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_nbrchar(-1, "0123456789abcdef", 1));
	return (0);
} */

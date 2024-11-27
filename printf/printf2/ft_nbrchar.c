/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:52:23 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/27 10:47:00 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	msize(long int a, char *base)
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
char	*motor(long int nbr, char *base, char *final)
{
	long int		size;
	long int		k;
	long int		nb;
	long int		i;

	size = ft_strlen(base);
	i = ft_strlen(final);
	k = msize(nbr, base) - 1;
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

char	*ft_nbrchar(int nbr, char *base, int unsigned1, char *mainmalloc)
{
	if (unsigned1 == 1)
	{
		mainmalloc = motor((unsigned int)nbr, base, mainmalloc);
		return (mainmalloc);
	}
	mainmalloc = motor(nbr, base, mainmalloc);
	return (mainmalloc);
}

/* #include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_nbrchar(-1, "0123456789abcdef", 1));
	return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:52:23 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/21 18:09:33 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
int	msize(int a, char *base)
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
char	*motor(int nbr, char *base, char *final)
{
	long int		size;
	long int		k;
	long int		nb;

	size = 0;
	while (base[size] != '\0')
		size++;
	k = msize(nbr, base) - 1;
	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
		final[0] = '-';
	}
	while (k > 0 && nb >= size)
	{
		final[k] = base[nb % size];
		nb = nb / size;
		k--;
	}
	final[k] = base[nb];
	return (final);
}

char	*ft_nbrchar(int nbr, char *base)
{
	long int		a;
	long int		len_to;
	char			*numb;

	len_to = msize(nbr, base);
	numb = malloc(len_to * sizeof(char) + 1);
	if (!numb)
		return(NULL);
	numb[len_to] = '\0';
	numb = motor(nbr, base, numb);
	return (numb);
}


/* 
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_putnbr_base(34534535, "0123456789abcdef"));
	return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:52:23 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/21 17:30:57 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	link1(long nb, char *base)
{
	int			size;

	size = 0;
	while (base[size] != '\0')
		size++;
	if (size < 2)
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb < size)
		write(1, &base[nb], 1);
	else
	{
		link1(nb / size, base);
		link1(nb % size, base);
	}
}

int	ft_putnbr_base(long nb, char *base)
{
	int	i;

	link1(nb, base);
	i = ft_sizenbr_base(nb, base, 0);
	return (i);
}
/* 
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_putnbr_base(34534535, "0123456789abcdef"));
	return (0);
} */

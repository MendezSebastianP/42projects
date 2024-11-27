/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:49:39 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/27 10:47:50 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_adress(void *ptr, int verbose)
{
	unsigned long address;
	int	i;

	i = 0;
	address = (unsigned long)ptr;
	if (verbose == 0)
	{
		if (ptr)
		{
			i = ft_sizenbr_base(address, "0123456789abcdef", 0) + 2;
			return (i);
		}
		else
			return (5);
	}
	if (ptr)
	{
		write(1, "0x", 2);
	}
	else
	{	write(1, "(nil)", 5);
		return(5);
	}
	i = ft_putnbr_base(address, "0123456789abcdef");
	return (i + 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adresschar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:49:39 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/21 18:00:27 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	ft_adresschar(void *ptr, int verbose)
{
	unsigned long address;
	int	i;

	i = 0;
	address = (unsigned long)ptr;
	if (ptr)
	{
		write(1, "0x", 2);
	}
	else
	{	write(1, "(nil)", 5);
		return(5);
	}
	i = ft_atoi_base(address, "0123456789abcdef");
	return (i + 2);
}

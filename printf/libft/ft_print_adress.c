/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:49:39 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/18 14:17:24 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_adress(void *ptr)
{
	unsigned long address;

	address = (unsigned long)ptr;
	write(1, "0X", 2);
	ft_putnbr_base(address, "0123456789abcdef");
}
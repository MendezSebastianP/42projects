/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adresschar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:49:39 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/27 16:38:35 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*motoradress(unsigned long address, char *mainmalloc, int index)
{
	unsigned long	tmp;
	int				j;

	j = 0;
	tmp = address;
	while (tmp)
	{
		j++;
		tmp /= 16;
	}
	while (j-- > 0)
	{
		mainmalloc[index + j] = "0123456789abcdef"[address % 16];
		address /= 16;
	}
	return (mainmalloc);
}

char	*ft_adresschar(void *ptr, char *mainmalloc, int index)
{
	unsigned long	address;
	char			*nil1;
	int				i;

	address = (unsigned long)ptr;
	nil1 = "(nil)";
	i = 0;
	if (!ptr)
	{
		while (nil1[i])
		{
			mainmalloc[index + i] = nil1[i];
			i++;
		}
		return (mainmalloc);
	}
	mainmalloc[index++] = '0';
	mainmalloc[index++] = 'x';
	mainmalloc = motoradress(address, mainmalloc, index);
	return (mainmalloc);
}

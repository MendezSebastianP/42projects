/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adresschar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:49:39 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/27 10:46:28 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_adresschar(void *ptr, char *mainmalloc)
{
	unsigned long address;
	int	i;

	address = (unsigned long)ptr;
	i = ft_strlen(mainmalloc);
	if (!ptr)
	{
		mainmalloc[i++] = '(';
		mainmalloc[i++] = 'n';
		mainmalloc[i++] = 'i';
		mainmalloc[i++] = 'l';
		mainmalloc[i++] = ')';
		return (mainmalloc);
	}
	mainmalloc[i++] = '0';
	mainmalloc[i++] = 'x';
	mainmalloc = ft_nbrchar(address, "0123456789abcdef", 1, mainmalloc);
	return (mainmalloc);
}

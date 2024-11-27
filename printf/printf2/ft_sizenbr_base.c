/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizenbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:34:46 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/27 10:48:14 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sizenbr_base(long int numb, char *base, int unsigned1)
{
	long int	i;
	long int	sizeb;

	i = 1;
	sizeb = ft_strlen(base);
	if (unsigned1 == 1)
	{
		numb = (unsigned int)numb;
	}
	if (numb == -2147483648)
		numb = -2147483647;
	if (numb < 0)
	{
		i++;
		numb = numb * -1;
	}
	if ((numb / sizeb) == 0)
		return (i);
	while ((numb / sizeb) > 0)
	{
		numb = numb / sizeb;
		i++;
	}
	return (i);
}

/* #include <stdio.h>
int	main(void)
{
	long int a = -20;
	printf("%d\n", ft_sizenbr_base(a, "0123456789abcdef", 1));
	return (0);
} */

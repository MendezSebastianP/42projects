/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizenbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:34:46 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/20 18:55:38 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizenbr_base(long int numb, char *base)
{
	long int	i;
	long int	sizeb;

	i = 1;
	sizeb = 0;
	while (base[sizeb])
		sizeb++;
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
/* 
#include <stdio.h>
int	main(void)
{
	printf("%d\n", sizenbr_base(34534535, "0123456789abcdef"));
	return (0);
}
 */
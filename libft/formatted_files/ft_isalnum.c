/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:39:58 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/04 12:40:00 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c > 64 & c < 91) || (c > 96 & c < 123) || (c > 47 & c < 58))
		return (1);
	else
		return (0);
}

#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	a;

	a = '1';
	printf("Intended result: %d \n", isalnum(a));
	printf("Our result		: %d", ft_isalnum(a));
	return (0);
}

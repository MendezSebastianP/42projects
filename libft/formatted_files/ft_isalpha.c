/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:40:09 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/04 12:40:12 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c > 64 & c < 91) || (c > 96 & c < 123))
		return (1);
	else
		return (0);
}

#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	a;

	a = 'V';
	printf("Intended result: %d \n", isalpha(a));
	printf("Our result		: %d", ft_isalpha(a));
	return (0);
}

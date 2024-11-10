/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:40:44 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/08 18:23:24 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c < 178)
		return (1);
	else
		return (0);
}

/* #include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	a;

	a = 'a';
	printf("Intended result	: %d \n", isascii(a));
	printf("Our result	: %d", ft_isascii(a));
	return (0);
} */

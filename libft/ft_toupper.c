/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:42:53 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/10 15:26:52 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int ch)
{
	int	a;

	if (ch < 97 || ch > 122)
		return (ch);
	a = ch - 32;
	return (a);
}
/* 
#include <ctype.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	(void)argc;
	printf("Our result		: %c \n", ft_toupper(argv[1][0]));
	printf("Intended result : %c", toupper(argv[1][0]));
	return (0);
}
 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:32:20 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/07 13:37:00 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

#include <ctype.h>
#include <stdio.h>

void	ft_toupperalternate(unsigned int i, char *ch)
{
	if (i % 2 == 0 && !(*ch < 97 || *ch > 122))
		*ch = *ch - 32;
}
int	main(void)
{
	char	b1[50] = "vamos a ver si funciona";

	ft_striteri(b1, ft_toupperalternate);
	printf("Result: %s", b1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:37:11 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/15 12:57:04 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str1;
	int		i;

	i = 0;
	str1 = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (str1 == NULL)
		return (NULL);
	while (s[i])
	{
		str1[i] = f(i, s[i]);
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
/* 
#include <ctype.h>
#include <stdio.h>

char	ft_toupperalternate(unsigned int i, char ch)
{
	if (ch < 97 || ch > 122)
		return (ch);
	if (i % 2 == 0)
		ch = ch - 32;
	return (ch);
}
int	main(void)
{
	char	*b1;

	b1 = "vamos a ver si funciona";
	printf("Result: %s", ft_strmapi(b1, ft_toupperalternate));
	return (0);
}
 */
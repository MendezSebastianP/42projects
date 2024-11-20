/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:39:10 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/20 14:50:16 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_match(char *base, char b)
{
	int	i;

	i = 0;
	while (base[i] != b)
	{
		if (base[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

int	error(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (base[i + j] != '\0')
		{
			if (base[i] == base[i + j + 1])
				return (1);
			j++;
		}
		if (base[i] == 32 || base[i] == 43 || base[i] == 45
			|| (base[i] > 8 && base[i] < 14))
			return (1);
		i++;
	}
	if (i < 2)
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	while ((ft_match(base, str[i]) < 0 && str[i] != '\0') || error(base) == 1)
	{
		if (str[i] == 45)
			j++;
		if ((str[i] != 43 && str[i] != 45) || error(base) == 1)
			return (0);
		i++;
	}
	while (ft_match(base, str[i]) >= 0 && str[i] != '\0')
	{
		k = k * ft_strlen(base) + ft_match(base, str[i]);
		i++;
	}
	if (j % 2 == 1)
		return (k * -1);
	return (k);
}
/*
#include <stdio.h>
int	main(void)
{
	char*	str;
	char*	base;
	
	str = " \n---2147483648";
	base = "012345\n6789";
	printf("%d\n", ft_atoi_base(str, base));
	str = "\n    \n   \r\t\v\n      +-+-+-+++++----+-91597ag8481";
	base = "0123456789";
	printf("%d\n", ft_atoi_base(str, base));
	str = " \n\r\r--++++101010";
	base = "01";
	printf("%d\n", ft_atoi_base(str, base));
	str = " \n\r\r--++-+--ff";
	base = "0123456789abcdef";
	printf("%d\n", ft_atoi_base(str, base));
	return(0);
}
*/
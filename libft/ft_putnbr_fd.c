/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:27:03 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/11 18:00:56 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	powerf(int b)
{
	int	c;

	c = 1;
	while (b > 0)
	{
		c = c * 10;
		b = b - 1;
	}
	return (c);
}

int	maxn(int a1, int fd)
{
	if (a1 == -2147483648)
	{
		write(fd, "-214748364", 10);
		a1 = 8;
	}
	if (a1 < 0)
	{
		write(fd, "-", 1);
		a1 = a1 * -1;
	}
	return (a1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	b1;
	int	d1;
	int	i;

	n = maxn(n, fd);
	b1 = n;
	i = 0;
	while (b1 >= 10)
	{
		b1 = b1 / 10;
		i = i + 1;
	}
	while (i > 0)
	{
		b1 = n / powerf(i);
		d1 = b1 + 48;
		write(fd, &d1, 1);
		n = n % powerf(i--);
	}
	b1 = n + 48;
	write(fd, &b1, 1);
}
/* 
#include <stdlib.h>

int	main(int c, char *v[])
{
	(void)c;
	ft_putnbr_fd(atoi(v[1]), 1);
	write(1, "\n", 1);
	return (0);
} */

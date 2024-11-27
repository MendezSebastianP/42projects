/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:27:03 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/27 16:35:54 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (s[i] == '\0')
			write(fd, "\0", 1);
		else
			write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

/* int	main(int c, char *v[])
{
	char	*a;

	(void)c;
	a = v[1];
	ft_putstr_fd(a, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}
 */
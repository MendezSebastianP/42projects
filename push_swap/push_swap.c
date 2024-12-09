/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:36:58 by smendez-          #+#    #+#             */
/*   Updated: 2024/12/09 19:27:18 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int	is_single_dup(char *a, char *b)
{
	int	i;
	int	j;
	int	len_a;
	int	len_b;

	if (!a || !b)
		return (-1);
	i = 0;
	len_a = ft_strlen(a);
	len_b = ft_strlen(b);
	if (len_a != len_b)
		return(0);
	while (a[i])
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_dup(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i + 1])
	{
		j = i;
		while (argv[j + 1])
		{
			if (is_single_dup(argv[i], argv[j + 1]) > 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
// add function is min max
int	swap_iserror(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			if (ft_isdigit(argv[i][j]) != 1 || !argv[i][j])
				return (1);
			j++;
		}
		i++;
	}
	if (is_dup(argc, argv) > 0)
		return (1);
	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	ft_printf("Test result: (%s == %s) -> %d", argv[1], argv[2], is_single_dup(argv[1], argv[2]));
// 	return (0);
// }

// int	main(int argc, char *argv[])
// {
// 	ft_printf("Test result -> %d", is_dup(argc, argv));
// 	return (0);
// }

int	main(int argc, char *argv[])
{
 	ft_printf("Test result -> %d", swap_iserror(argc, argv));
 	return (0);
}
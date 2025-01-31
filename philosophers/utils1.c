/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:22:11 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/29 13:24:34 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit_str(char *c)
{
	int	i;

	i = 0;
	if (!c[i])
		return (0);
	while (c[i])
	{
		if (c[i] > 47 && c[i] < 58)
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int	is_intoverflow(char *arg)
{
	int		i;
	int		j;
	char	*positive;

	i = 0;
	j = 0;
	positive = "2147483647";
	if ((ft_isdigit(arg[0]) == 1 && ft_strlen(arg) > 10) || (arg[0] == '-'
			&& ft_strlen(arg) > 11))
		return (1);
	if ((ft_isdigit(arg[0]) == 1 && ft_strlen(arg) < 10) || (arg[0] == '-'
			&& ft_strlen(arg) < 11))
		return (0);
	if (arg[0] == '-')
		j = 1 + i++;
	while (arg[i + 1])
	{
		if (arg[i] > positive[i - j])
			return (1);
		i++;
	}
	if (arg[i] > '7' + j)
		return (1);
	return (0);
}

int	is_valid(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (0);
	if (ft_isdigit_str(argv[1]) == 0 || ft_isdigit_str(argv[2]) == 0)
		return (0);
	if (ft_isdigit_str(argv[3]) == 0 || ft_isdigit_str(argv[4]) == 0)
		return (0);
	if (argv[5])
	{
		if (ft_isdigit_str(argv[5]) == 0)
			return (0);
	}
	while (argv[i])
	{
		if (is_intoverflow(argv[i]) == 1)
			return (0);
		i++;
	}
	return (1);
}

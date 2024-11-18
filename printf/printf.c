/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:02:58 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/18 15:26:49 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
//cc printf.c -Llibft -lft 

int	isformat(const char c)
{
	int	i;
	char *set;

	i = 0;
	set = "cspdiuxX%";
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	countargs(char *format)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (format[i])
	{
		if(format[i] == '%' && isformat(format[i + 1]) == 1)
		{
			j++;
			i++;
		}
		i++;
	}
	return (j);
}


int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	nargs;
	
	i = 0;
	//nargs = countargs(format);
	va_start(args, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i] && isformat(format[i + 1]))
		{
			ft_putchar_fd(format[i], 1);
			i++;
		}
		if (format[i + 1] == 'c')
		{
			ft_putchar_fd(va_arg(args, int), 1);
			i++;
		}
		else if (format[i + 1] == 's')
		{
			ft_putstr_fd(va_arg(args, char*), 1);
			i++;
		}
		else if (format[i + 1] == 'p')
		{
			ft_print_adress(va_arg(args, void*));
			i++;
		}
		else if (format[i + 1] == 'd' || format[i] == 'i' || format[i] == 'i')
		{
			ft_putnbr_fd(va_arg(args, int), 1);
			i++;
		}
		else if (format[i + 1] == 'i' || format[i] == 'i' || format[i] == 'i')
		{
			ft_putnbr_fd(va_arg(args, int), 1);
			i++;
		}
		else if (format[i + 1] == 'u' || format[i] == 'i' || format[i] == 'i')
		{
			ft_putnbr_fd(va_arg(args, int), 1);
			i++;
		}
		else if (format[i + 1] == 'x')
		{
			ft_putnbr_base(va_arg(args, unsigned long), "0123456789abcdef");
			i++;
		}
		else if (format[i + 1] == 'X')
		{
			ft_putnbr_base(va_arg(args, unsigned long), "0123456789ABCDEF");
			i++;
		}
		else if (format[i + 1] == '%')
		{
			ft_putchar_fd('%', 1);
			i++;
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

#include <stdio.h>
int	main(void)
{
	char *t = "Weno, el primer resultado:";
	long int a = -2147483649;
	ft_printf("Our result	: %s %d %i %u|\n", t, a, a, a);
	printf("Intended result	: %s %d %i %u|\n", t, a, a, a);
	return (0);
}

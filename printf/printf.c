/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:02:58 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/20 20:02:45 by smendez-         ###   ########.fr       */
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
	int	j;
	
	i = 0;
	j = 0;
	va_start(args, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i] && isformat(format[i + 1]))
		{
			ft_putchar_fd(format[i++], 1);
			j++;
		}
		if (format[i + 1] == 'c')
		{
			ft_putchar_fd(va_arg(args, int), 1);
			j++;
			i++;
		}
		else if (format[i + 1] == 's')
		{
			j = ft_putstr_fd(va_arg(args, char*), 1) + j;
			i++;
		}
		else if (format[i + 1] == 'p')
		{
			j = ft_print_adress(va_arg(args, void*)) + j;
			i++;
		}
		else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		{
			j = ft_putnbr_base(va_arg(args, int), "0123456789") + j;
			i++;
		}
		else if (format[i + 1] == 'u')
		{
			j = ft_putnbr_unsigned_fd(va_arg(args, unsigned int)) + j;
			i++;
		}
		else if (format[i + 1] == 'x')
		{
			j = ft_putnbr_base(va_arg(args, unsigned long), "0123456789abcdef") + j;
			i++;
		}
		else if (format[i + 1] == 'X')
		{
			j = ft_putnbr_base(va_arg(args, unsigned long), "0123456789ABCDEF") + j;
			i++;
		}
		else if (format[i + 1] == '%')
		{
			ft_putchar_fd('%', 1);
			i++;
			j++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			j++;
		}
		if (format[i])
			i++;
	}
	va_end(args);
	return (j);
}

#include <stdio.h>
int	main(void)
{
	int	result;
	int	result_native;
	char	c = 'T';
	char	*s = "working               vbghgh";
	int a = -153454;
	int *p = &a;
	int t1 = ft_printf("Our result      : %c   %s   %p %d %i %u %x %X%%|\n", c, s, p, a, a, a, a, a);
	int t2 =    printf("Intended result : %c   %s   %p %d %i %u %x %X%%|\n", c, s, p, a, a, a, a, a);
	// int t1 = ft_printf("%c\n", c);
	// int t2 =    printf("%c\n", c);
	printf("Ncharacters: Ours: %d\n intended %d\n", t1, t2);
	return (0);
}

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

int	sizearg(const char format,va_list args)
{
	int	j;

	j = 0;
	if (format == 'c')
		j = ft_putchar_fd(va_arg(args, int), 1, 0);
	else if (format == 's')
		j = ft_strlen(va_arg(args, char*));
	else if (format == 'p')
		j = ft_print_adress(va_arg(args, void*), 0);
	else if (format == 'd' || format == 'i')
		j = ft_sizenbr_base(va_arg(args, int), "0123456789");
	else if (format == 'u')
		j = ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 0);
	else if (format == 'x')
		j = ft_sizenbr_base(va_arg(args, int), "0123456789abcdef");
	else if (format == 'X')
		j = ft_sizenbr_base(va_arg(args, int), "0123456789ABCDEF");
	else if (format == '%') // attention
		j = 1;
	va_end(args);
	return (j);
	
}

int	sizeprintf(const char *format,va_list args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (format[i])
	{
		if (format[i] == '%' && isformat(format[i + 1]))
		{
			j += sizearg(format[i + 1], args);
			i += 2;
		}
		else
		{
			i++;
			j++;
		}
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
	i = sizeprintf(format, args);
	va_end(args);
	return (i);
}

/* int	printarg(const char *format,va_list args)
{
	int	j;

	if (format[0] == 'c')
		j = ft_putchar_fd(format, 1);
	else if (format[0] == 's')
		j = ft_strlen(va_arg(args, char*));
	else if (format[0] == 'p')
		j = ft_print_adress(va_arg(args, void*));
	else if (format[0] == 'd' || format[0] == 'i')
		j = ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (format[0] == 'u')
		j = ft_putnbr_unsigned_fd(va_arg(args, unsigned int));
	else if (format[0] == 'x')
		j = ft_putnbr_base(va_arg(args, unsigned long), "0123456789abcdef");
	else if (format[0] == 'X')
		j = ft_putnbr_base(va_arg(args, unsigned long), "0123456789ABCDEF");
	else if (format[0] == '%')
		j = ft_putchar_fd('%', 1);
	else
		j = ft_putchar_fd(format[0], 1);
	va_end(args);
	return (j);
	
} */
#include <stdio.h>
int	main(void)
{
	int	result;
	int	result_native;
	char	c = 'T';
	char	*s = "wo";
	int a = -13634;
	//int *p = &a;
	// int t1 =  ft_printf("Our result      : %c   %s   %p %d %i %u %x %X%%|\n", c, s, s, a, a, a, a, a);
	// int t2 =     printf("Intended result : %c   %s   %p %d %i %u %x %X%%|\n", c, s, s, a, a, a, a, a);
	int t1 =  ft_printf("\n\n%s%p%d%i%u%x%X%%|\n", s, s, a, a, a, a, a);
	int t2 =     printf("\n\n%s%p%d%i%u%x%X%%|\n", s, s, a, a, a, a, a);
	printf("\nNcharacters: Ours: %d\n intended %d\n", t1, t2);
	return (0);
}
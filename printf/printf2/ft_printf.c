#include "printf.h"


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
		j = ft_sizenbr_base(va_arg(args, int), "0123456789", 0);
	else if (format == 'u')
		j = ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 0);
	else if (format == 'x')
		j = ft_sizenbr_base(va_arg(args, int), "0123456789abcdef", 1);
	else if (format == 'X')
		j = ft_sizenbr_base(va_arg(args, int), "0123456789ABCDEF", 1);
	else if (format == '%') // attention
		j = 1;
	va_end(args);
	return (j);
	
}
int	argchar(const char format,va_list args)
{
	char	*j;

	j = 0;
	if (format == 'c')
		j = va_arg(args, char*);
	else if (format == 's')
		j = va_arg(args, char*);
	else if (format == 'p')
		j = ft_print_adress(va_arg(args, void*), 0);
	else if (format == 'd' || format == 'i')
		j = ft_sizenbr_base(va_arg(args, int), "0123456789", 0);
	else if (format == 'u')
		j = ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 0);
	else if (format == 'x')
		j = ft_sizenbr_base(va_arg(args, int), "0123456789abcdef", 1);
	else if (format == 'X')
		j = ft_sizenbr_base(va_arg(args, int), "0123456789ABCDEF", 1);
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
	va_list args1;
	char	*chr;
	int	sz;
	int	i;
	
	va_start(args, format);
	sz = sizeprintf(format, args);
	chr = malloc((sz + 1) * sizeof(char));
	if (!chr)
		return (0);
	i = 0;
	while (format[i])
	{

	}
	va_end(args);
	va_end(args1);
	return (sz);
}

#include <stdio.h>
int	main(void)
{
	int	result;
	int	result_native;
	char	c = 'T';
	char	*s = "wo";
	int a = -13634;
	//int *p = &a;
	int t1 =  ft_printf("Our result      : %c   %s   %p %d %i %u %x %X%%|\n", c, s, s, a, a, a, a, a);
	int t2 =     printf("Intended result : %c   %s   %p %d %i %u %x %X%%|\n", c, s, s, a, a, a, a, a);
	// int t1 =  ft_printf("\n\n%s%p%d%i%u%x%X%%|\n", s, s, a, a, a, a, a);
	// int t2 =     printf("\n\n%s%p%d%i%u%x%X%%|\n", s, s, a, a, a, a, a);
	printf("\nNcharacters: Ours: %d\n intended %d\n", t1, t2);
	return (0);
}
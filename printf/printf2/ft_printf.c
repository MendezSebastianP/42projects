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
		j = ft_strlennull(va_arg(args, char*));		
	else if (format == 'p')
		j = ft_print_adress(va_arg(args, void*), 0);
	else if (format == 'd' || format == 'i')
		j = ft_sizenbr_base(va_arg(args, int), "0123456789", 0);
	else if (format == 'u')
		j = ft_sizenbr_base(va_arg(args, int), "0123456789", 1);
	else if (format == 'x')
		j = ft_sizenbr_base(va_arg(args, int), "0123456789abcdef", 1);
	else if (format == 'X')
		j = ft_sizenbr_base(va_arg(args, int), "0123456789ABCDEF", 1);
	else if (format == '%')
		j = 1;
	return (j);
}
char	*argchar(const char format,va_list args, char *mainmalloc)
{
	int	i;

	i = ft_strlen(mainmalloc);
	if (format == 'c')
		mainmalloc[i] = va_arg(args, int);
	else if (format == 's')
	{
		mainmalloc = ft_straddend(mainmalloc, va_arg(args, char*));
	}
	else if (format == 'p')
		mainmalloc = ft_adresschar(va_arg(args, void*), mainmalloc);
	else if (format == 'd' || format == 'i')
		mainmalloc = ft_nbrchar(va_arg(args, int), "0123456789", 0, mainmalloc);
	else if (format == 'u')
		mainmalloc = ft_nbrchar(va_arg(args, int), "0123456789", 1, mainmalloc);
	else if (format == 'x')
		mainmalloc = ft_nbrchar(va_arg(args, int), "0123456789abcdef", 1, mainmalloc);
	else if (format == 'X')
		mainmalloc = ft_nbrchar(va_arg(args, int), "0123456789ABCDEF", 1, mainmalloc);
	else if (format == '%')
		mainmalloc[i] = '%';
	return (mainmalloc);
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
	va_copy(args1, args);
	sz = sizeprintf(format, args);
	chr = ft_calloc((sz + 1), sizeof(char));
	if (!chr)
		return (0);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && isformat(format[i + 1]))
			{
				chr = argchar(format[i + 1], args1, chr);
				i += 2;
			}
		else
			chr = ft_charaddend(chr, format[i++]);
	}
	ft_putstr_fd(chr, 1);
	free(chr);
	va_end(args);
	va_end(args1);
	return (sz);
}

#include <stdio.h>
int	main(void)
{
	int	result;
	int	result_native;
	char	c = '\0';
	char	*s = NULL;
	int a = -13634;
	//int *p = &a;
	// int t1 =  ft_printf("Our result      : %c   %s   %p %d %i %u %x %X%%|\n", c, s, s, a, a, a, a, a);
	// int t2 =     printf("Intended result : %c   %s   %p %d %i %u %x %X%%|\n", c, s, s, a, a, a, a, a);
	int t2 =     printf("Intended result : %c   %s   %p %d %i %u %x %X%%|\n", c, s, s, a, a, a, a, a);
	int t1 =  ft_printf("Our result      : %c   %s   %p %d %i %u %x %X%%|\n", c, s, s, a, a, a, a, a);
	printf("\nNcharacters: Ours: %d\n intended %d\n", t1, t2);
	return (0);
}

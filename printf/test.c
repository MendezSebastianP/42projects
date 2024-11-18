#include <unistd.h>

void	ft_putnbr_base(unsigned long nb, char *base)
{
	int			size;

	size = 0;
	while (base[size] != '\0')
		size++;
	if (size < 2)
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb < size)
		write(1, &base[nb], 1);
	else
	{
		ft_putnbr_base(nb / size, base);
		ft_putnbr_base(nb % size, base);
	}
}
void	ft_print_adress(void *ptr)
{
	unsigned long address;

	address = (unsigned long)ptr;
	write(1, "0X", 2);
	ft_putnbr_base(address, "0123456789abcdef");

}

#include <stdio.h>
int	main(void)
{
	char *t = "haha";
	print_adress(t);
	printf("\n%p\n", t);
	return 0;
}
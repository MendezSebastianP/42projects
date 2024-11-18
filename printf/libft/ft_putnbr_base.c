#include "libft.h"

void	ft_putnbr_base(long nb, char *base)
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
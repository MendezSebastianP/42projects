int	ft_atoi(const char *s)
{
	int	i;
	int	j;
	long	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] == 32 || (s[i] > 8 && s[i] < 14))
		i++;
	while ((s[i] < 48 || s[i] > 57) && s[i] != '\0')
	{
		if (s[i] == 45 && s[i + 1] != 43 && j < 1)
			j++;
		else if (s[i] != 43 || s[i + 1] == 43 || s[i + 1] == 45)
			return (0);
		i++;
	}
	while (s[i] > 47 && s[i] < 58)
	{
		k = k * 10 + s[i] - 48;
		i++;
	}
	if (j == 1)
		return (k * -1);
	return (k);
}


#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	(void)argc;
	printf("Our result	: %d \n", ft_atoi(argv[1]));
	printf("Intended result	: %d", atoi(argv[1]));
	return(0);
}
#include <stdlib.h>

int	powerf(int b)
{
	int	c;

	c = 1;
	while (b > 0)
	{
		c = c * 10;
		b = b - 1;
	}
	return (c);
}

#include <stdio.h>
int main(int c, char *v[])
{
    (void)c;
    printf("Number size: %d", powerf(atoi(v[1]))  );
    return (0);
}
void ft_ft(int *nbr)
{
    *nbr = 42;
}
#include <stdio.h>
int main()
{
    int n = 10;
	ft_ft(&n);
    printf("result %d", n);   
    return 0;
}
int ft_isdigit(int c)
{
    if (c > 47 & c < 58)
        return(1);
    else
        return (0);
    
}

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char a = '1';
    printf("Intended result: %d \n", isdigit(a));
    printf("Our result     : %d", ft_isdigit(a));
    return (0);
}
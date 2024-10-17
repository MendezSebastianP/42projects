int ft_isalnum(int c)
{
    if ((c > 64 & c < 91) || (c > 96 & c < 123) || (c > 47 & c < 58))
        return(1);
    else
        return (0);
    
}

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char a = '1';
    printf("%d \n", isalnum(a));
    printf("%d", ft_isalnum(a));
    return (0);
}
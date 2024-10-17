int ft_isascii(int c)
{
    if (c >= 0 & c < 178)
        return(1);
    else
        return (0);
    
}

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char a = 'é';
    printf("%d \n", isascii(a));
    printf("%d", ft_isascii(a));
    return (0);
}
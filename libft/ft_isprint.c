int ft_isprint(int c)
{
    if (c > 31 & c < 127)
        return(1);
    else
        return (0);
    
}

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char a = ' ';
    printf("%d \n", isprint(a));
    printf("%d", ft_isprint(a));
    return (0);
}
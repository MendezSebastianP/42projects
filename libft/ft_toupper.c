int ft_toupper(int ch)
{
    int a;

    if(ch < 97 || ch > 122)
    return(ch);
    a = ch - 32;
    return (a);
}

#include <stdio.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
    (void)argc;
    printf("Our result      : %c \n", ft_toupper(argv[1][0]));
    printf("Intended result : %c", toupper(argv[1][0]));
    return (0);
}
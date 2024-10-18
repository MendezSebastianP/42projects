int ft_strlen(char *c)
{
    int i;

    i = 0;

    while (c[i] != '\0')
        i++;

    return (i);
}

#include <string.h>
#include <stdio.h>

int main(void)
{
    char *a = "Vamos a contar";
    printf("%d \n", strlen(a));
    printf("%d", ft_strlen(a));
    return (0);
}
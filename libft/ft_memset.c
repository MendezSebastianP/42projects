
#include <stddef.h>

void    *ft_memset(void *str, int c, size_t n)
{
    size_t i;
    unsigned char *ptr;

    i = 0;
    ptr = str;
    while (i < n)
    {
        ptr[i] = c;
        i++;
    }
    return str;
}

#include <string.h>
#include <stdio.h>

int main(void)
{
    char str1[11];
    char str2[11];
    memset(str1, '#', 10);
    str1[10] = '\0';
    ft_memset(str2, '#', 10);
    str2[10] = '\0';
    printf("Intended result: %s \n", str1);
    printf("Our result     : %s", str2);
    return (0);
}
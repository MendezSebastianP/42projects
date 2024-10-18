
#include <stddef.h>

void    *ft_bzero(void *str, size_t n)
{
    size_t i;
    unsigned char *ptr;
    int c;

    c = '0';
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
    //char str1[50] = "Testons si ca marche ou pas";
    //char str2[50] = "Testons si ca marche ou pas";
    int str1[10] = {1,2,3,4,5,6,7,8,9,0};
    int str2[10] = {1,2,3,4,5,6,7,8,9,0};
    bzero(str1, 4);
    //str1[27] = '\0';
    ft_bzero(str2, 4);
    //str2[27] = '\0';
    printf("%s \n", str1);
    printf("%s", str2);
    return (0);
}
/* Needed to return NULL, if not it doesnt work :( */
#include <stddef.h> 

void *ft_memchr(const void *str, int c, size_t n)
{
    int i;
    const char *ptr;

    ptr = str;
    i = 0;
    while(ptr[i] != c && i != n)
        i++;
    if (ptr[i] == c)
        return((char *)(str + i));
    else
        return (NULL);
    
}

#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    (void)argc;
    char *l1 = ft_memchr(argv[1], argv[2][0], strlen(argv[1]));
    char *l2 = memchr(argv[1], argv[2][0], strlen(argv[1]));
    printf("Our result      : %s \n", l1);
    printf("Intended result : %s", l2);
    return (0);
}
/* This function is very usefull to count how many times you find a character
or to find the index (printf("position:%ld", result - text)) */

/* int main(int argc, char *argv[])
{
    (void)argc;
    int i = 0;
    int j = 0;
    char *a = argv[1];

    printf("The letter |%c| is found at index: %ld \n",argv[2][0], ft_memchr(a, argv[2][0]) - a);
    a = ft_memchr(a + 1, argv[2][0]);
    while(a != NULL)
    {
        a = ft_memchr(a + 1, argv[2][0]);
        printf("Also... letter |%c| is found at position: %ld \n",argv[2][0], ft_memchr(a, argv[2][0]) - argv[1]);
    }
    return (0);
} */
/* Needed to return NULL, if not it doesnt work :( */
#include <stddef.h> 

char    *ft_strchr(const char *str, int search_str)
{
    int i;

    i = 0;
    while(str[i] != search_str && str[i] != '\0')
        i++;
    if (str[i] == search_str)
        return((char *)(str + i));
    else
        return (NULL);
    
}

#include <stdio.h>
/* #include <string.h>
int main(int argc, char *argv[])
{
    (void)argc;
    printf("Our result      : %s \n", ft_strchr(argv[1], argv[2][0]));
    printf("Intended result : %s", strchr(argv[1], argv[2][0]));
    return (0);
} */
/* This function is very usefull to count how many times you find a character
or to find the index (printf("position:%ld", result - text)) */

int main(int argc, char *argv[])
{
    (void)argc;
    int i = 0;
    int j = 0;
    char *a = argv[1];

    printf("The letter |%c| is found at index: %ld \n",argv[2][0], ft_strchr(a, argv[2][0]) - a);
    a = ft_strchr(a + 1, argv[2][0]);
    while(a != NULL)
    {
        a = ft_strchr(a + 1, argv[2][0]);
        printf("Also... letter |%c| is found at position: %ld \n",argv[2][0], ft_strchr(a, argv[2][0]) - argv[1]);
    }
    return (0);
}
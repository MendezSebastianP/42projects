#include <stdlib.h>

int ft_strlen(const char *c)
{
    size_t i;

    i = 0;
    while (c[i] != '\0')
        i++;
    return (i);
}

void    *ft_substr(char const *s, unsigned int start, size_t len)
{
        unsigned char    *t;
        size_t  i;

        i = 0;
        t = malloc(len * sizeof(char) + 1);
        if (t == NULL)
                return (NULL);
        while (len > i)
        {
                t[i] = s[i + start];
                i++;
        }
        t[i] = '\0';
        return (t);
}

#include <stdio.h>
#include <string.h>

int     main(int argc, char *argv[])
{
        (void)argc;
        char *str = argv[1];
        int start = atoi(argv[2]);
        int len = atoi(argv[3]);
        char *s1 = ft_substr(str, start, len);;
        /* char *s2 = substr(str, start, len); */
        printf("Our result     : %s\n", s1);
        /* printf("Intended result: %s", s2); */
        free(s1);
        /* free(s2); */
        return(0);
} 



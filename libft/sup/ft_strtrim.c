#include <stdlib.h>

int isin(const char *set, const char c)
{
    size_t i;

    i = 0;
    while (set[i] != '\0')
    {
        if (set[i] == c)
                return (1);
        i++;    
    }
    return (0);
}
int ft_strlentrim(const char *c, const char *set)
{
        size_t  i;
        size_t  j;
        size_t  k;
        
        i = 0;
        j = 0;
        k = 0;

        while (c[k])
                k++;
        while (isin(set, c[i]) == 1)
                i++;
        while (isin(set, c[k - 1]) == 1)
                k--;
        return (k - i);
}

char    *ft_strtrim(char const *s1, const char *set)
{
        unsigned char    *t;
        size_t  i;
        size_t  j;
        size_t  sizetrim;

        i = 0;
        sizetrim = ft_strlentrim(s1, set);
        t = malloc(sizetrim  * sizeof(char) + 1);
        if (t == NULL)
                return (NULL);
        while (isin(set, s1[i]) == 1)
                i++;
        while (j < sizetrim)
        {
                t[j] = s1[i + j];
                j++;
        }
        t[i + j] = '\0';
        return (t);
}


#include <stdio.h>
#include <string.h>

int     main(int argc, char *argv[])
{
        (void)argc;
        char *s1 = ft_strtrim(argv[1], argv[2]);;
        /* char *s2 = strtrim(str, start, len); */
        printf("Our result     : %s\n", s1);
        /* printf("Intended result: %s", s2); */
        free(s1);
        /* free(s2); */
        return(0);
} 



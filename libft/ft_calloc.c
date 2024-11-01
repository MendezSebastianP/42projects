#include <stdlib.h>

int     ft_strlen(char *a)
{
        int     i;

        i = 0;
        while (a[i] != '\0')
                i++;
        return (i);
}

void    *ft_calloc(size_t nitems, size_t size)
{
        unsigned char    *t;
        size_t     i;

        i = 0;
        t = malloc(nitems * size + 1);
        if (t == NULL)
                return (NULL);
        while (nitems * size > i)
        {
                t[i] = 0;
                i++;
        }
        if (size == sizeof(char))
                t[i] = '\0';
        return (t);
}

#include <stdio.h>
#include <stdlib.h>

/* int     main(int argc, char *argv[])
{
        (void)argc;
        printf("Our result     : %d \n", ft_atoi(argv[1]));
        printf("Intended result: %d", atoi(argv[1]));
        return(0);
} */

int     main(int argc, char *argv[])
{
        (void)argc;
        int n = atoi(argv[1]);
        int *s1;
        int *s2;
        int i = 0;

        s1 = (int*)ft_calloc(n, sizeof(int));
        s2 = (int*)calloc(n, sizeof(int));
        printf("Our result     : ");
        while(i < n)
        {
                printf("%d ", s1[i]);
                i++;
        }
        i = 0;
        printf("\n");
        printf("Intended result: ");
        while(i < n)
        {
                printf("%d ", s2[i]);
                i++;
        }
        printf("\n");
        free(s1);
        free(s2);
        return(0);
} 



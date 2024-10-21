#include <stddef.h>

unsigned int    ft_strlcpy(char *dest, char *src, size_t size)
{
        size_t   i;

        i = 0;
        if (size != 0)
        {
                while (i < size - 1 && src[i] != '\0')
                {
                        dest[i] = src[i];
                        i++;
                }
                dest[i] = '\0';
        }
        while (src[i] != '\0')
        {
                i++;
        }
        return (i);
}

#include <stdio.h>
#include <string.h>

int     main(void)
{
        char    *src;
        char    dest[20];
        size_t  copiedlen;

        src = "Hello, world!";
        copiedlen = ft_strlcpy(dest, src, 8);
        printf("Copied string: %s\n", dest);
        printf("Expected length: %lu, Copied length: %lu\n", strlen(src), copiedlen);
        return (0);
}

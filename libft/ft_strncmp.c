#include <stddef.h>

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
        unsigned int    j;
        unsigned int    i;

        if (n == 0)
                return (0);
        i = 0;
        j = 0;
        while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
                i++;
        j = s1[i] - s2[i];
        return (j);
}

/* #include <stdio.h>
#include <string.h>

int main() {
    char str[] = "aa";
    char str2[] = "aa";
    int sum1;
    int sum2;

    sum1 = ft_strncmp(str, str2, strlen(str2));
    sum2 = strncmp(str, str2, strlen(str2));
    printf("our result: %d \n", sum1);
    printf("intended result: %d", sum2);
    return 0;
} */

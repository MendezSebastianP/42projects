#include <stdlib.h>

int lent2(char *s1, char c1, int t1)
{
    int i;
    int j;
    int k;
    
    i = 0;
    k = -1;
    while (s1[i])
    {
        j = 0;
        while (s1[i] == c1)
        i++;
        while (s1[i] != c1 && s1[i])
        {
            i++;
            j++;
        }
        if (s1[i] == c1 || !s1[i])
        k++;
        if (k == t1)
        return (j);
    }
    return (0);
}

#include <stdio.h>
int main(int c, char *v[])
{
    (void)c;
    printf("lenght: %d", lent2(v[1], v[2][0], atoi(v[3])));
    return (0);
}
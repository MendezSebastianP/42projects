#include "pipex.h"

int     isin_str(char *str, char *c)
{
    int i;
    int j;

    i = 0;
    while(c[i])
    {
        if (c[i] != str[i])
                return (0);
        i++;
    }
    return (1);
}

int ft_count_c(char *str, char *c)
{
    int i;
    int j;
    int len_c;

    i = 0;
    j = 0;
    len_c = ft_strlen(c);
    while(str[i])
    {
        if(isin_str(str + i, c) == 1)
        {
                j++;
                i = i + len_c;
        }
        else
                i++;
    }
    return (j);
}

char    *ft_replace(char *str, char *r, char *old)
{
    int i;
    int j;
    int k;
    int len_r;
    char    *new_str;

    i = 0;
    j = 0;
    len_r = ft_strlen(r);
    new_str = malloc((ft_strlen(str) + ft_count_c(str, old) * (len_r - 1) + 1));
    if (!new_str)
        return (NULL);
    while(str[i])
    {
        k = 0;
        if(isin_str(str + i, old) == 1)
        {
                while (r[k])
                        new_str[j++] = r[k++];
            i = i + ft_strlen(old);
        }
        new_str[j++] = str[i++];
    }
    new_str[j] = '\0';
    return (new_str);
}

char *replaceif(char *str)
{
        if ((ft_count_c(str, "'") % 2) != 0)
                return (str);
        
}

int main(int argc, char *argv[])
{
        char *test = ft_replace(argv[1], argv[2], argv[3]);
        printf("%s\n", test);
        free(test);
        return (0);
}

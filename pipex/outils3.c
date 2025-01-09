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

char *ft_cut(char *str, int start, int end)
{
        int i;
        int j;
        char *temp;

        i = 0;
        temp = malloc(end - start + 1);
        if(!temp)
                return (NULL);
        while (start < end && str[start])
        {
                temp[i++] = str[start++];
        }
        temp[i] = '\0';
        return (temp);
}

int next_c(char *str, char c)
{
        int i;

        i = 0;
        while (str[i] != c && str[i])
                i++;
        return (i);
}
char *ft_step_in(char *str)
{
        int i;
        int j;
        int k;
        char *temp;
        char *temp2;
        char *base;

        if ((ft_count_c(str, "\'") % 2) != 0 || ft_count_c(str, "\'") == 0)
                return (str);
        k = ft_count_c(str, "\'") / 2;
        i = next_c(str, '\'');
        temp = ft_strdup(str);
        while (k > 0)
        {
                (base = ft_cut(temp, 0, i), free(temp));
                temp2 = ft_cut(temp, i, i + 2 + next_c(temp + i + 1, '\''));
                temp2 = ft_replace(temp2, "+++", " ");
                temp2 = ft_strjoin(base, temp2);
                i = i + 2 + next_c(temp + i + 1, '\'');
                temp = ft_strjoin(temp2, temp + i);
                i = ft_strlen(temp2) + next_c(temp + ft_strlen(temp2), '\'');
                (free(temp2), free(base), k--);
        }
        return (temp);
}

/* int main(int argc, char *argv[])
{
        char *test = ft_step_in(argv[1]);
        printf("%s\n", test);
        free(test);
        return (0);
} */

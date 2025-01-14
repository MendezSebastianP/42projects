#include "pipex.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char			*t;
	size_t			i;
	size_t			nitems;

	i = 0;
	nitems = ft_strlen(s);
	t = malloc(nitems * sizeof(char) + 1);
	if (t == NULL)
		return (NULL);
	while (nitems > i)
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	unsigned char	*t;
	size_t			i;
	size_t			k;

	i = 0;
	k = nitems * size;
	t = malloc(k);
	if (t == NULL || (size != 0 && k / size != nitems))
		return (NULL);
	while (nitems * size > i)
	{
		t[i] = 0;
		i++;
	}
	return (t);
}

void ft_close_all(int **fd)
{
	int i;
	int j;

	i = 0;
	while (fd[i])
	{
		j = 0;
		while (j < 2)
		{
			close(fd[i][j++]);
		}
		i++;
	}
}

int	ft_isequalstr(char *str1, char *str2)
{
	int len1;
	int len2;
	int i;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 != len2)
		return (0);
	i = 0;
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

// int	main(int argc, char *argv[])
// {
// 	char *test = "hola";
// 	printf("is equal? %d\n", ft_isequalstr(argv[1], test));
// 	return (0);
// }

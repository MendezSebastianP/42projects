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

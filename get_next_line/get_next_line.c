/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:37:03 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/28 19:54:30 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
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

static int	isin(const char *set, const char c, int buffersize)
{
	int	i;

	i = 0;
	while (buffersize > i)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_realloc(char *oldlloc, size_t buffersize)
{
	char	*t;
	size_t			i;
	size_t			k;

	i = 0;
	k = 0;
	while(oldlloc[i])
		i++;
	t = malloc(i + buffersize + 1);
	if (t == NULL)
		return (NULL);
	while (i + buffersize > k)
	{
		t[k] = 0;
		k++;
	}
	while(i != 0)
	{
		t[i - 1] = oldlloc[i - 1];
		i--;
	}
	free(oldlloc);
	return (t);
}

char	*ft_straddend(char *malloc1, char *toadd, int buffersize)
{
	int		i;
	int		j;
	char *str;

	i = 0;
	j = 0;
	str = ft_calloc(ft_strlen(malloc1)+ ft_strlen(toadd) +1, 1);
	while (malloc1[i])
	{
		str[i] = malloc1[i];
		i++;
	}
	while (buffersize > j && toadd[j])
	{
		str[i + j] = toadd[j];
		j++;
	}
	return (str);
}

char	*ft_resetbase(char *base)
{
	int	i;
	int	j;
	char	*newlloc;
	
	i = 0;
	j = 0;
	while (base[i] && base[i] != '\n')
		i++;
	while (base[i + j])
		j++;
	if (!base[i + 1])
	{
		free(base);
		base = malloc(1);
		return (base);
	}
	newlloc = malloc(j);
	if (!newlloc)
		return (NULL);
	while (j < 0)
	{
		newlloc[j] = base[j + i];
		j--;
	}
	free(base);
	return (newlloc);
}


char	*ft_strdup(const char *s)
{
	char			*t;
	size_t			i;
	size_t			nitems;

	i = 0;
	nitems = 0;
	while (s[nitems])
		nitems++;
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

char	*get_next_line(int fd)
{
	static char	*base;
	char		*b1;
	char		*line;
	int		sizeb;

	b1 = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!b1)
		return (NULL);
	sizeb = BUFFER_SIZE;
	if (!base)
		base = ft_calloc(1,sizeof(char));
	while (isin(b1, '\n', BUFFER_SIZE) == 0 && sizeb == BUFFER_SIZE)
	{
		//base = ft_realloc(base, BUFFER_SIZE);
		sizeb = read(fd, b1, BUFFER_SIZE);
		base = ft_straddend(base, b1, BUFFER_SIZE);
	}
	line = ft_strdup(base);
	base = ft_resetbase(base);
	free(b1);
	if (sizeb != BUFFER_SIZE)
		free(base);
	return (line);
}
// mettre base a 0 a la fin
#include <stdio.h>
int main()
{
	int	fd;
	char	*a1;
	char	*a2;

	fd = open("test1.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file");
	}
	a1 = get_next_line(fd);
	printf("%s", a1);
	free(a1);
	// a2 = get_next_line(fd);
	// printf("%s", a2);
	// free(a2);
	// a2 = get_next_line(fd);
	// printf("%s", a2);
	// free(a2);

    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:37:03 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/28 14:35:58 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static int	isin(const char *set, const char c, int buffersize)
{
	size_t	i;

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
	unsigned char	*t;
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

	i = 0;
	j = 0;
	while (malloc1[i])
		i++;
	while (buffersize > j)
	{
		malloc1[i + j] = toadd[j];
		j++;
	}
	return (malloc1);
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
	if (j == 0)
	{
		free(base);
		return (malloc(1));
	}
	newlloc = malloc(j);
	if (!newlloc)
		return (NULL);
	while (j == 0)
	{
		newlloc[j] = base[j + i];
		j--;
	}
	free(base);
	return (newlloc);
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

char	*get_next_line(int fd)
{
	static char	*base;
	char		*b1;
	int		sizeb;

	b1 = ft_calloc(BUFSIZ);
	sizeb = BUFSIZ;
	if (!b1)
		return (NULL);
	while (isin(b1, '\n', BUFSIZ) == 0 && sizeb == BUFSIZ)
	{
		base = realloc(base, BUFSIZ);
		sizeb = read(fd, b1, BUFSIZ);
		base = ft_straddend(base, b1, BUFSIZ);
	}
	
}

#include <stdio.h>
int main()
{
    // if file does not have in directory
    // then file foo.txt is created.
    int fd = open("test1.txt", O_RDONLY);
    printf("fd = %d\n", fd);
    int fd1 = open("test2.txt", O_RDONLY);
    printf("fd = %d\n", fd1);
    int fd2 = open("test3.txt", O_RDONLY);
    printf("fd = %d\n", fd2);
    int fd3 = open("test4.txt", O_RDONLY);
    printf("fd = %d\n", fd3);

    char *c = get_next_line(fd);
    printf("Those bytes are as follows: %s\n", c);
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:37:03 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/29 18:07:09 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_straddend(char *malloc1, char *toadd, int buffersize)
{
	int		i;
	int		j;
	char *str;

	i = 0;
	j = 0;
	if (!malloc1)
		return (ft_strdup(toadd));
	str = ft_calloc(ft_strlen(malloc1)+ ft_strlen(toadd) + 1, 1);
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
	free(malloc1);
	return (str);
}

char	*ft_resetbase(char *base)
{
	int	i;
	int	j;
	int	k;
	char	*newlloc;
	
	i = 0;
	j = 0;
	k = 0;
	while (base[i] && base[i] != '\n')
		i++;
	j = ft_strlen(base + i + 1);
	if (!base[i + 1])
	{
		free(base);
		return (ft_calloc(1, 1));
	}
	newlloc = malloc(j);
	if (!newlloc)
		return (NULL);
	while (j > k)
		newlloc[k++] = base[i++ + 1];
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
	while (s[nitems] && s[nitems - 1] != '\n')
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
		sizeb = read(fd, b1, BUFFER_SIZE);
		base = ft_straddend(base, b1, BUFFER_SIZE);
	}
	line = ft_strdup(base);
	base = ft_resetbase(base);
	free(b1);
	// if (sizeb != BUFFER_SIZE || isin(base, '\n', BUFFER_SIZE) != 1) // adjakdjhs
	// 	free(base);
	if (sizeb < 0 || (!base[0] && sizeb == 0)) // Erreur ou EOF sans contenu.
	{
		free(base);
		base = NULL;
		return (NULL);
	}
	return (line);
}

// mettre base a 0 a la fin
/* #include <stdio.h>
int main()
{
	int	fd;
	char	*a1;
	char	*a2;

	fd = open("testa.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file");
	}
	a1 = get_next_line(fd);
	printf("%s", a1);
	free(a1);
	a2 = get_next_line(fd);
	printf("%s", a2);
	free(a2);
	a2 = get_next_line(fd);
	printf("%s", a2);
	free(a2);
	// a2 = get_next_line(fd);
	// printf("%s", a2);
	// free(a2);

    return 0;
} */

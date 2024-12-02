/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:37:03 by smendez-          #+#    #+#             */
/*   Updated: 2024/12/02 11:35:04 by smendez-         ###   ########.fr       */
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
	if (!toadd)
        	return (malloc1);
	if (!malloc1)
		return (ft_strdup(toadd, 0));
	str = ft_calloc(ft_strlen(malloc1)+ ft_strlen(toadd) + 1, 1);
	if (!str)
		return (NULL);
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
	char	*newlloc;
	
	i = 0;
	if (!base)
		return (NULL);
	while (base[i] && base[i] != '\n')
		i++;
	if (!base[i])
	{
		free(base);
		return (ft_calloc(1, 1));
	}
	newlloc = ft_strdup(base + i + 1, 0);
	if (!newlloc)
		return (NULL);
	
	free(base);
	return (newlloc);
}


char	*ft_strdup(const char *s, int line)
{
	char			*t;
	size_t			i;
	size_t			nitems;

	i = 0;
	nitems = 0;
	while (s[nitems])
	{
		if (nitems > 0 && s[nitems - 1] == '\n' && line == 1)
			break;
		nitems++;
	}
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

char	*freenull(char **base)
{
	free(*base);
	*base = NULL;
	return (NULL);
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
	if (!base)
		base = ft_calloc(1,sizeof(char));
	sizeb = 0;
	while (isin(base, '\n', ft_strlen(base)) == 0 && (sizeb = read(fd, b1, BUFFER_SIZE)) > 0)
	{
		base = ft_straddend(base, b1, sizeb);
		if (!base)
			return (freenull(&b1));
	}
	free(b1);
	if (sizeb < 0 || (!base[0] && sizeb == 0))
		return (freenull(&base));
	line = ft_strdup(base, 1);
	base = ft_resetbase(base);
	return (line);
}


#include <stdio.h>
int main()
{
	int	fd;
	char	*a1;
	char	*a2;

	fd = open("empty.txt", O_RDONLY);
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
	// a2 = get_next_line(fd);
	// printf("%s", a2);
	// free(a2);
	// a2 = get_next_line(fd);
	// printf("%s", a2);
	// free(a2);
	// a2 = get_next_line(fd);
	// printf("%s", a2);
	// free(a2);
	// a2 = get_next_line(fd);
	// printf("%s", a2);
	// free(a2);
    return 0;
}

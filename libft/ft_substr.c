/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:36:28 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/10 15:24:39 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

void	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*t;
	size_t			i;

	i = 0;
	t = malloc(len * sizeof(char) + 1);
	if (t == NULL)
		return (NULL);
	while (len > i)
	{
		t[i] = s[i + start];
		i++;
	}
	t[i] = '\0';
	return (t);
}
/* 
#include <stdio.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	char	*str;
	int		start;
	int		len;
	char	*s1;

	(void)argc;
	str = argv[1];
	start = atoi(argv[2]);
	len = atoi(argv[3]);
	s1 = ft_substr(str, start, len);
	printf("Our result		: %s\n", s1);
	free(s1);
	return (0);
}
 */
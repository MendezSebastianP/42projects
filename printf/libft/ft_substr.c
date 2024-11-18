/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:36:28 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/15 11:50:19 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*t;
	size_t			i;
	size_t			slen;

	i = 0;
	slen = ft_strlen(s) - start;
	if ((slen) > len)
		slen = len;
	if (start >= ft_strlen(s) || ft_strlen(s) == 0 || len == 0)
		slen = 0;
	t = malloc((slen + 1) * sizeof(char));
	if (t == NULL)
		return (NULL);
	while (slen > i)
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
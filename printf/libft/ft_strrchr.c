/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:42:44 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/15 10:05:42 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Needed to return NULL, if not it doesnt work :( */
#include <stddef.h>

char	*ft_strrchr(const char *str, int search_str)
{
	int				i;
	unsigned char	s_str;

	i = 0;
	s_str = (unsigned char)search_str;
	while (str[i])
		i++;
	while (str[i] != s_str && i > 0)
		i--;
	if (str[i] == s_str)
		return ((char *)(str + i));
	else
		return (NULL);
}
/* 
#include <stdio.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	(void)argc;
	printf("Our result	: %s \n", ft_strrchr(argv[1], argv[2][0]));
	printf("Intended result	: %s", strrchr(argv[1], argv[2][0]));
	return (0);
} */

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char s[] = "tripouille";
	printf("Our result	: %s \n", ft_strrchr(s, 0));
	printf("Intended result	: %s \n", strrchr(s, 0));
	printf("Our result	: %d \n", ft_strrchr(s, 0) == s + strlen(s));
	printf("Intended result	: %d", strrchr(s, 0) == s + strlen(s));
	return (0);
}  */
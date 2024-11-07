/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:42:44 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/04 12:42:45 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Needed to return NULL, if not it doesnt work :( */
#include <stddef.h> 

char	*ft_strrchr(const char *str, int search_str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	i--;
	while(str[i] != search_str && i > 0)
		i--;
	if (str[i] == search_str)
		return((char *)(str + i));
	else
		return (NULL);
	
}

#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	(void)argc;
	printf("Our result	  : %s \n", ft_strrchr(argv[1], argv[2][0]));
	printf("Intended result : %s", strrchr(argv[1], argv[2][0]));
	return (0);
}

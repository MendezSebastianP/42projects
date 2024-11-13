/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:35:37 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/13 15:09:08 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	splitlen(char const *s1, char c1)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s1[i])
	{
		while (s1[i] == c1 && s1[i])
			i++;
		if (s1[i])
			k++;
		while(s1[i] != c1 && s1[i])
			i++;
	}
	return (k);
}

char	**cleanexit(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
	return (NULL);
}

char	*t2f(char const *s, int start_s, char c)
{
	int		i;
	int		j;
	int		len_s;
	char	*t2;

	i = 0;
	j = start_s;
	len_s = 0;
	while (s[j] != c && s[j])
	{
		len_s++;
		j++;
	}
	t2 = malloc((len_s + 1) * sizeof(char));
	if (t2 == NULL)
		return (NULL);
	while (i < len_s)
	{
		t2[i] = s[start_s + i];
		i++;
	}
	t2[i] = '\0';
	return (t2);
}

char	**ft_split(char const *s, char c)
{
	char	**t1;
	int		i;
	int		j;

	t1 = malloc((splitlen(s, c) + 1) * sizeof(char*));
	if (t1 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		t1[j] = t2f(s, i, c);
		if (t1[j] == NULL)
			cleanexit(t1);
		j++;
		while (s[i] != c && s[i])
			i++;
	}
	t1[j] = NULL;
	return (t1);
}

/* #include <stdio.h>

int	main(int c, char *v[])
{
	int		i;
	char	**a;

	(void)c;
	i = 0;
	a = ft_split(v[1], v[2][0]);
	while (a[i])
	{
		printf("%s\n", a[i]);
		i++;
	}
	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
	return (0);
}
 */
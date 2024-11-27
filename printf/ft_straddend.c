/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:01:52 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/27 16:36:10 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_straddend(char *malloc1, char *toadd, int index)
{
	int		i;
	int		j;
	char	*a;

	i = index;
	j = 0;
	a = "(null)";
	if (!toadd)
	{
		while (a[j])
		{
			malloc1[i + j] = a[j];
			j++;
		}
		return (malloc1);
	}
	while (toadd[j])
	{
		malloc1[i + j] = toadd[j];
		j++;
	}
	return (malloc1);
}

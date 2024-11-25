/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:01:52 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/25 17:37:57 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_straddend(char *malloc1, char *toadd)
{
	int	i;
	int	j;
	char	*a;
	
	i = 0;
	j = 0;
	a = "(null)";
	while (malloc1[i])
		i++;
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

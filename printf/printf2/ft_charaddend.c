/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charaddend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:01:52 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/25 16:25:52 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_charaddend(char *malloc1, char toadd)
{
	int	i;
	
	i = 0;
	while (malloc1[i])
		i++;


	malloc1[i] = toadd;	
	return (malloc1);
}

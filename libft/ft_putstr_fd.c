/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:27:03 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/06 16:03:01 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void    ft_putstr_fd(char *s, int fd)
{
    int i;

    i = 0;
    while (s[i])
    {
        write(fd, &s[i], 1);
        i++;
    }
}

int main(int c, char *v[])
{
    (void)c;
    char *a = v[1];
    ft_putstr_fd(a,1);
    ft_putstr_fd("\n",1);
    return (0);
}

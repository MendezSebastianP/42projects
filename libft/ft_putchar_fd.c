/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:27:03 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/06 15:55:18 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

int main(void)
{
    char a = 'T';
    ft_putchar_fd(a,0);
    ft_putchar_fd('\n',1);
    return (0);
}

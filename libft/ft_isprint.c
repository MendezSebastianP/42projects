/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:40:58 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/04 12:40:59 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isprint(int c)
{
    if (c > 31 & c < 127)
        return(1);
    else
        return (0);
    
}

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char a = ' ';
    printf("Intended result: %d \n", isprint(a));
    printf("Our result     : %d", ft_isprint(a));
    return (0);
}
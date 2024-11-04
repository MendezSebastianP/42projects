/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:40:52 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/04 12:40:55 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isdigit(int c)
{
    if (c > 47 & c < 58)
        return(1);
    else
        return (0);
    
}

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char a = '1';
    printf("Intended result: %d \n", isdigit(a));
    printf("Our result     : %d", ft_isdigit(a));
    return (0);
}
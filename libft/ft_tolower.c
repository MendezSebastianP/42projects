/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:42:48 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/04 12:42:49 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_tolower(int ch)
{
    int a;

    if(ch < 65 || ch > 90)
    return(ch);
    a = ch + 32;
    return (a);
}

#include <stdio.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
    (void)argc;
    printf("Our result      : %c \n", ft_tolower(argv[1][0]));
    printf("Intended result : %c", tolower(argv[1][0]));
    return (0);
}
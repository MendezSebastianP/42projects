/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:30:42 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/21 17:30:10 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdarg.h>

int	ft_print_adress(void *ptr, int verbose);
int	ft_printf(const char *format, ...);
int	ft_putchar_fd(char c, int fd, int verbose);
int	ft_putnbr_base(long nb, char *base);
int	ft_putnbr_unsigned_fd(unsigned int k, int verbose);
int	ft_putstr_fd(char *s, int fd);
int	ft_sizenbr_base(long int numb, char *base, int unsigned1);
size_t	ft_strlen(const char *c);


#endif //FT_H

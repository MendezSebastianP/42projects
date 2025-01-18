/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:30:42 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/18 17:17:43 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../includes/src.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_printf_fd(int fd, const char *format, ...);
char				*ft_nbrchardec(int nbr, int unsigned1, char *mainmalloc,
						int index);
int					ft_sizenbr_base(long int numb, char *base, int unsigned1);
char				*ft_straddend1(char *malloc1, char *toadd, int index);
char				*ft_nbrcharhex(int nbr, char *base, char *mainmalloc,
						int index);
size_t				ft_strlennull(const char *c);
int					ft_print_adress(void *ptr);
int					ft_putstr_fd(char *s, int fd, int size);
char				*ft_adresschar(void *ptr, char *mainmalloc, int index);
int					isformat(const char c);
size_t				ft_strlen(const char *c);

#endif //FT_H

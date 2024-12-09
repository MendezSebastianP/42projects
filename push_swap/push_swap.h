/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:30:42 by smendez-          #+#    #+#             */
/*   Updated: 2024/12/09 17:51:57 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_adresschar(void *ptr, char *mainmalloc, int index);
char	*ft_nbrchardec(int nbr, int unsigned1, char *mainmalloc, int index);
int		isformat(const char c);
char	*ft_nbrcharhex(int nbr, char *base, char *mainmalloc, int index);
int		ft_print_adress(void *ptr);
int		ft_printf(const char *format, ...);
int		ft_putstr_fd(char *s, int fd, int size);
int		ft_sizenbr_base(long int numb, char *base, int unsigned1);
char	*ft_straddend(char *malloc1, char *toadd, int index);
size_t	ft_strlen(const char *c);
size_t	ft_strlennull(const char *c);

#endif //FT_H

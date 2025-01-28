/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:30:42 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/28 13:18:05 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H
# include "ft_printf_fd.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strjoin(char const *s1, const char *s2);
int	isin(const char *set, const char c);
size_t	ft_strlen(const char *c);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nitems, size_t size);
char	**ft_split(char const *s, char c);
char	**cleanexit(char **a);
int	n_c(char **map);
char	**df(char *str);
char    *read_txt(char *file);
int	str_len_2d(char **str);


#endif //FT_H

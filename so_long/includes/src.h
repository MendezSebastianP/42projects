/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:30:42 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/28 14:56:15 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H
# include "ft_printf_fd.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char const *s1, const char *s2);
int		isin(const char *set, const char c);
size_t	ft_strlen(const char *c);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nitems, size_t size);
char	**ft_split(char const *s, char c);
char	**cleanexit(char **a);
int		n_c(char **map);
char	**df(char *str);
char	*read_txt(char *file);
int		str_len_2d(char **str);

void	step(char **map);
int		equalto_one(char base, char a, char b);
void	foward(char **map, int j, int i);
int		if_foward(char **map, int j, int i);
int		if_wall(char **map);
void	step2(char **map);
int		is_c(char **map);
int		at_least_one(char **map);
int		is_missletter(char **map);
char	**strdup_2d(char **s);
int		is_exit(char **map, int i, int j);
int		is_map_error(char *path);

#endif //FT_H

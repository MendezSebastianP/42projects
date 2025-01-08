/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:30:42 by smendez-          #+#    #+#             */
/*   Updated: 2024/12/23 16:51:54 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_straddend(char *malloc1, char *toadd, int buffersize);
char	*ft_resetsc(char *base);
char	*get_all_lines(int fd);
size_t	sl(const char *c);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_realloc(char *oldlloc, size_t buffersize);
char	*ft_strtrim(char const *s1, const char *set);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, const char *s2);
size_t	ft_strlen(const char *c);
char	*ft_strdup(const char *s);
int     isin_str(char *str, char *c);


#endif //FT_H

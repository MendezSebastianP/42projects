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
char	*ft_strdup(const char *s, int line);
char	*get_all_lines(int fd);
size_t	sl(const char *c);
void	*ft_calloc(size_t nitems, size_t size);
int		isin(const char *set, const char c, int buffersize);
char	*ft_realloc(char *oldlloc, size_t buffersize);

#endif //FT_H

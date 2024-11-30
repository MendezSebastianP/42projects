/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:30:42 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/30 14:03:46 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*ft_straddend(char *malloc1, char *toadd, int buffersize);
char	*ft_resetbase(char *base);
char	*ft_strdup(const char *s, int line);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *c);
void	*ft_calloc(size_t nitems, size_t size);
int	isin(const char *set, const char c, int buffersize);
char	*ft_realloc(char *oldlloc, size_t buffersize);

#endif //FT_H

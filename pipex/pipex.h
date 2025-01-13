/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:30:42 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/13 13:23:33 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}           t_list;


char	**ft_split(char *s, char c);
char	*ft_strjoin(char const *s1, const char *s2);
size_t	ft_strlen(const char *c);
char	*ft_strdup(const char *s);
char	**cleanexit(char **a);
void ft_close_all(int **fd);


#endif //FT_H

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:30:42 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/16 16:22:48 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// pipex
char				*ft_strjoin(char const *s1, const char *s2);
size_t				ft_strlen(const char *c);
char				*ft_strdup(const char *s);
void				ft_close_all(int **fd);
int					ft_isequalstr(char *str1, char *str2);
char				**get_path(char *envp[]);
char				*get_path_command(char **paths, char *command);
char				*no_args_cmd(char *cmd);
void				perror_exit(char *msg);
void				pid0(int **fd1, char *argv[], char **paths, int i);
void				pid1(int **fd1, char *argv[], char **paths, int out);
char				*cleanexit2(int **a);
int					**ft_add_fd(int **fd, int len);
void				wait_all(int *pid, int len);
// bonus
int					pid_pipe(int **fd1, char *argv[], char **paths, int i);
void				pipe_withcall(int *fd);
int					multi_pipex(int argc, char *argv[], char **paths, int **fd);

// modified split
char				**cleanexit(char **a);
int					splitlen(char const *s1, char c1);
char				**ft_split(char *s, char c);

// get next line
char				*ft_straddend(char *malloc1, char *toadd, int buffersize);
char				*ft_resetsc(char *base);
char				*ft_strdup2(const char *s, int line);
char				*get_next_line(int fd);
size_t				sl(const char *c);
void				*ft_calloc2(size_t nitems, size_t size);
char				*ft_realloc(char *oldlloc, size_t buffersize);
void				ft_until_limiter(char *argv);
int					isin1(const char *set, const char c, int buffersize);

#endif //FT_H

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:30:42 by smendez-          #+#    #+#             */
/*   Updated: 2024/12/10 14:54:32 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

char	*ft_adresschar(void *ptr, char *mainmalloc, int index);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
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
int	swap_iserror(int argc, char *argv[]);


#endif //FT_H

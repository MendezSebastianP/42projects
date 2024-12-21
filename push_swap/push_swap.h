/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:30:42 by smendez-          #+#    #+#             */
/*   Updated: 2024/12/21 14:07:21 by smendez-         ###   ########.fr       */
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
    void            *content;
    struct s_list   *next;
}           t_list;

// printf
void	print_s1(t_list *b1);
void	print_s2(t_list *b1, t_list *b2);
int	ft_printf(const char *format, ...);
char	*ft_nbrchardec(int nbr, int unsigned1, char *mainmalloc, int index);
int	ft_sizenbr_base(long int numb, char *base, int unsigned1);
char	*ft_straddend(char *malloc1, char *toadd, int index);
char	*ft_nbrcharhex(int nbr, char *base, char *mainmalloc, int index);
size_t	ft_strlen(const char *c);
size_t	ft_strlennull(const char *c);
int	ft_print_adress(void *ptr);
int	ft_putstr_fd(char *s, int fd, int size);
char	*ft_adresschar(void *ptr, char *mainmalloc, int index);
int	isformat(const char c);


// movements push swap
void sswap(t_list **list);
void	ss(t_list **list_a, t_list ** list_b);
void spush(t_list **list_a, t_list **list_b);
void	rotate(t_list **list);
void	rr(t_list **list_a, t_list ** list_b);
void	r_rot(t_list **list);
void	rrr(t_list **list_a, t_list ** list_b);

// linked list functions
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// push_swap
int	swap_iserror(int argc, char *argv[]);
char *free_list(t_list *list);
t_list	*ptr_to_numblist(char *argv[]);

#endif //FT_H

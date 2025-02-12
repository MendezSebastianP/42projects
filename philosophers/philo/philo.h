/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:28:18 by smendez-          #+#    #+#             */
/*   Updated: 2025/02/12 15:29:22 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// Bibliothèques standard
# include <errno.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				num_philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				meals_required;
	int				is_dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	long long		start_time;
}					t_data;

typedef struct s_philosopher
{
	int				id;
	int				meals_eaten;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
	long long		last_meal;
}					t_philosopher;

typedef struct s_list
{
	t_philosopher	*philo;
	struct s_list	*next;
}					t_list;

int					ft_isdigit_str(char *c);
int					ft_strlen(const char *c);
int					ft_atoi(const char *s);
int					ft_isdigit(int c);
int					is_intoverflow(char *arg);
int					is_valid(int argc, char **argv);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(void *content);
char				*free_list(t_list *list);
t_philosopher		*start_p(int id, t_data *data);
t_list				*start_philos(char **argv, t_data *data, int i);

int					start_data(int argc, char **argv, t_data *data);
int					eat(t_philosopher *philo);
int					ph_sleep(t_philosopher *philo);
int					think(t_philosopher *philo);
void				*monitor(void *arg);

void				*action(void *arg);

#endif
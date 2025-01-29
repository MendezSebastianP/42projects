/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:28:18 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/29 15:40:45 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

// Bibliothèques standard
#include <stdio.h>      // Pour printf, perror
#include <stdlib.h>     // Pour malloc, free, exit
#include <string.h>     // Pour memset, strerror
#include <unistd.h>     // Pour write, usleep, fork, execve, pipe, dup, dup2, close, access, unlink
#include <sys/time.h>   // Pour gettimeofday
#include <pthread.h>    // Pour pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
#include <errno.h>      // Pour les codes d'erreur

typedef struct s_data {
    int num_philos;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    int meals_required;
    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex;
    long long start_time;
} t_data;

typedef struct s_philosopher {
    int id;
    int meals_eaten;
    pthread_t thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_data *data;
    long last_meal;
} t_philosopher;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

int	ft_isdigit_str(char *c);
int	ft_strlen(const char *c);
int	ft_isdigit(int c);
int	is_intoverflow(char *arg);
int is_valid(int argc, char **argv);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);



#endif
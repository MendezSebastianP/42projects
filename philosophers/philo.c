/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:27:43 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/29 20:11:21 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->content);
		free(tmp);
	}
	return (NULL);
}

t_philosopher   *start_p(int id, t_data *data)
{
        t_philosopher *philo;

        philo = malloc(sizeof(t_philosopher));
        if (!philo)
                exit(1);
        philo->id = id;
        philo->meals_eaten = 0;
        philo->data = data;
        philo->nothing = 0;
        philo->last_meal = philo->data->start_time;
        return (philo);
}

t_list *start_philos(char **argv, t_data *data)
{
        int     i;
        int     n_ph;
        t_list *ph_list;
        t_list *temp;
        t_philosopher *philo;
        t_philosopher *philo_last;

        i = 1;
        ph_list = NULL;
        n_ph = atoi(argv[1]);
        while (i <= n_ph)
        {
                philo = start_p(i, data);
                if (i != 1)
                {
                        philo->left_fork = philo_last->right_fork;
                }
                temp = ft_lstnew(philo);
                ft_lstadd_back(&ph_list, temp);
                philo_last = philo;
                printf("philo number: %d\n", i);
                i++;
        }
        philo = ph_list->content;
        philo->left_fork = philo_last->right_fork;
        data->forks = &philo_last->right_fork;
        return (ph_list);
}

void    start_data(int argc, char **argv, t_data *data)
{
        struct timeval time_t;
        long long sec;
        long micro;
        data->num_philos = atoi(argv[1]);
        data->time_to_die = atoi(argv[2]);
        data->time_to_eat = atoi(argv[3]);
        data->time_to_sleep = atoi(argv[4]);
        if (argc == 6)
                data->meals_required = atoi(argv[5]);
        else
                data->meals_required = -1;
        gettimeofday(&time_t, NULL);
        data->start_time = (time_t.tv_sec * 1000000) + time_t.tv_usec;
}
int    eat(t_philosopher *philo)
{
        struct timeval time_t;
        long long now;

        gettimeofday(&time_t, NULL);
        now = (time_t.tv_sec * 1000000) + time_t.tv_usec;

        if (philo->last_meal + (philo->data->time_to_die * 1000) < now)
        {
                printf("%lld %d died\n", (now - philo->data->start_time)/1000 , philo->id);
                return (-1);
        }
        philo->meals_eaten = philo->meals_eaten++;
        philo->last_meal = now;
        philo-> nothing = 1;
        printf("%lld %d is eating\n", (now - philo->data->start_time)/1000, philo->id);
        usleep(philo->data->time_to_eat * 1000);
        return (0);
}

int    ph_sleep(t_philosopher *philo)
{
        struct timeval time_t;
        long long now;

        gettimeofday(&time_t, NULL);
        now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
        if (philo->last_meal + (philo->data->time_to_die * 1000) < now)
        {
                printf("%lld %d died\n", (now - philo->data->start_time)/1000, philo->id);
                return (-1);
        }
        printf("%lld %d is sleeping\n", (now - philo->data->start_time)/1000, philo->id);
        usleep(philo->data->time_to_sleep * 1000);
        return (0);
}

int    think(t_philosopher *philo)
{
        struct timeval time_t;
        long long now;

        gettimeofday(&time_t, NULL);
        now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
        if (philo->last_meal + (philo->data->time_to_die * 1000) < now)
        {
                printf("%lld %d died\n", (now - philo->data->start_time)/1000, philo->id);
                return (-1);
        }
        printf("%lld %d is thinking\n", (now - philo->data->start_time)/1000, philo->id);
        return (0);
}

void    *action(void *arg)
{
        t_philosopher *philo;
        struct timeval time_t;

        gettimeofday(&time_t, NULL);
        philo = (t_philosopher *)arg;
        printf("id %d\n\n", philo->id);
        if (philo->id % 2 == 1)
        {
                pthread_mutex_lock(&philo->left_fork);
                pthread_mutex_lock(&philo->right_fork);
                if (eat(philo) == -1)
                        (exit(0));
                pthread_mutex_unlock(&philo->left_fork);
                pthread_mutex_unlock(&philo->right_fork);
                if (ph_sleep(philo) == -1)
                        (exit(0));
                if (think(philo) == -1)
                        (exit(0));
        }
        if (philo->id % 2 == 0)
        {
                usleep(1);
                pthread_mutex_lock(&philo->left_fork);
                pthread_mutex_lock(&philo->right_fork);
                if (eat(philo) == -1)
                        (exit(0));
                pthread_mutex_unlock(&philo->left_fork);
                pthread_mutex_unlock(&philo->right_fork);
                if (ph_sleep(philo) == -1)
                        (exit(0));
                if (think(philo) == -1)
                        (exit(0));
        }
        return (NULL);
}

int     main(int argc, char **argv)
{
        t_data *data;
        t_list *philos;
        pthread_t *threads;
        int     i;

        i = 0;
        if (is_valid(argc, argv) == 0)
                return (printf("Result: %d", is_valid(argc, argv)));
        data = malloc(sizeof(t_data));
        start_data(argc, argv, data);
        threads = malloc(sizeof(pthread_t) * data->num_philos);
        philos = start_philos(argv, data);
        while(i < data->num_philos)
        {
                pthread_create(&threads[i], NULL, action, philos->content);
                philos = philos->next;
                i++;
        }
        i = 0;
        while(i < data->num_philos)
        {
                pthread_join(threads[i++], NULL);
        }
        pthread_mutex_destroy(data->forks);
        free_list(philos);
        free(data);
        free(threads);
        return (0);
}

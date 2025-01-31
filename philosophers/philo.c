/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:27:43 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/31 17:29:36 by smendez-         ###   ########.fr       */
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
		free(tmp->philo);
		free(tmp);
	}
	return (NULL);
}

t_philosopher   *start_p(int id, t_data *data)
{
        t_philosopher *philo;

        philo = malloc(sizeof(t_philosopher));
        if (!philo)
                return (NULL);
        philo->id = id;
        philo->meals_eaten = 0;
        philo->data = data;
        philo->last_meal = philo->data->start_time;
        philo->left_fork = &data->forks[id - 1];
        philo->right_fork = &data->forks[(id) % data->num_philos];
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
                
                temp = ft_lstnew(philo);
                ft_lstadd_back(&ph_list, temp);
                philo_last = philo;
                printf("philo number: %d\n", i);
                i++;
        }
        ph_list->philo->left_fork = philo_last->right_fork;
        return (ph_list);
}

void    start_data(int argc, char **argv, t_data *data)
{
        struct timeval time_t;
        long long sec;
        long micro;
        int i;

        i = 0;
        data->num_philos = atoi(argv[1]);
        data->time_to_die = atoi(argv[2]);
        data->time_to_eat = atoi(argv[3]);
        data->time_to_sleep = atoi(argv[4]);
        data->is_dead = 0;
        if (argc == 6)
                data->meals_required = atoi(argv[5]);
        else
                data->meals_required = -1;
        printf("meals required: %d\n\n", data->meals_required); // delete
        gettimeofday(&time_t, NULL);
        data->start_time = (time_t.tv_sec * 1000000) + time_t.tv_usec;
        data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
        if (!data->forks)
                return ;
        while(i < data->num_philos)
                pthread_mutex_init(&data->forks[i++], NULL);
        pthread_mutex_init(&data->print_mutex, NULL);
}
int    eat(t_philosopher *philo)
{
        struct timeval time_t;
        long long now;

        if(philo->data->is_dead == 1)
                return (-1);
        gettimeofday(&time_t, NULL);
        now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
        philo->meals_eaten++;
        philo->last_meal = now;
        printf("%lld %d is eating\n", (now - philo->data->start_time)/1000, philo->id);
        usleep(philo->data->time_to_eat * 1000);
        return (0);
}



int    ph_sleep(t_philosopher *philo)
{
        struct timeval time_t;
        long long now;

        if(philo->data->is_dead == 1)
                return (-1);
        gettimeofday(&time_t, NULL);
        now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
        printf("%lld %d is sleeping\n", (now - philo->data->start_time)/1000, philo->id);
        usleep(philo->data->time_to_sleep * 1000);
        return (0);
}

int    think(t_philosopher *philo)
{
        struct timeval time_t;
        long long now;
        int eat;
        int sleep;

        if(philo->data->is_dead == 1)
                return (-1);
        eat = philo->data->time_to_eat;
        sleep = philo->data->time_to_sleep;
        gettimeofday(&time_t, NULL);
        now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
        printf("%lld %d is thinking\n", (now - philo->data->start_time)/1000, philo->id);
        if (philo->data->num_philos % 2 == 1)
                // usleep(((sleep < eat) * sleep) + ((sleep > eat) * eat));
                usleep(500);
        return (0);
}
void     *monitor(void *arg)
{
        int     i;
        t_list *philo;
        t_list *head;
        struct timeval time_t;
        long long now;

        head = (t_list *)arg;
        i = 0;
        while (1)
        {
                gettimeofday(&time_t, NULL);
                now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
                philo = head;
                if (i == (philo->philo->data->meals_required * philo->philo->data->num_philos))
                        return (NULL);
                i = 0;
                while (philo)
                {
                        i = philo->philo->meals_eaten + i;
                        if (philo->philo->last_meal + (philo->philo->data->time_to_die * 1000) < now)
                        {
                                printf("%lld %d died\n", (now - philo->philo->data->start_time)/1000, philo->philo->id);
                                philo->philo->data->is_dead = 1;
                                return (NULL);
                        }
                        philo = philo->next;
                }
        }
        
}
void    *action(void *arg)
{
        long long now;
        t_philosopher *philo;
        struct timeval time_t;

        philo = (t_philosopher *)arg;
        if (philo->id % 2 == 0)
                usleep(philo->data->time_to_eat * 1000);
        if (philo->data->num_philos % 2 == 1)
        {
                if (philo->id == (philo->data->num_philos))
                {
                        //printf("philo id %d, num philos %d\n\n", philo->id, philo->data->num_philos); // delete
                        usleep(philo->data->time_to_eat * 1000);
                }
        }
        while (1)
        {
                //printf("\n\ncheack meals\nmeals eaten=%d\nmals required=%d\n\n", philo->meals_eaten, philo->data->meals_required);
                if (philo->id % 2 == 1)
                {
                        pthread_mutex_lock(philo->left_fork);
                        gettimeofday(&time_t, NULL);
                        now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
                        if (philo->data->is_dead == 0)
                                printf("%lld %d has taken a fork\n", (now - philo->data->start_time)/1000, philo->id);
                        if (philo->data->num_philos == 1)
                                return (NULL);
                        pthread_mutex_lock(philo->right_fork);
                }
                else
                {       
                        pthread_mutex_lock(philo->right_fork);
                        gettimeofday(&time_t, NULL);
                        now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
                        if (philo->data->is_dead == 0)
                                printf("%lld %d has taken a fork\n", (now - philo->data->start_time)/1000, philo->id);
                        pthread_mutex_lock(philo->left_fork);
                }
                eat(philo);
                pthread_mutex_unlock(philo->left_fork);
                pthread_mutex_unlock(philo->right_fork);
                if (philo->meals_eaten == philo->data->meals_required)
                                return (NULL);
                if (ph_sleep(philo) == -1)
                        return (NULL);
                if (think(philo) == -1)
                        return (NULL);
        }
        return (NULL);
}

int     main(int argc, char **argv)
{
        t_data *data;
        t_list *philos;
        t_list *head;
        pthread_t *threads;
        int     i;

        i = 0;
        if (is_valid(argc, argv) == 0)
                return (printf("Result: %d", is_valid(argc, argv)));
        data = malloc(sizeof(t_data));
        start_data(argc, argv, data);
        threads = malloc(sizeof(pthread_t) * (data->num_philos + 1));
        philos = start_philos(argv, data);
        head = philos;
        while(i < data->num_philos)
        {
                pthread_create(&threads[i], NULL, action, philos->philo);
                philos = philos->next;
                i++;
        }
        philos = head;
        pthread_create(&threads[i], NULL, monitor, philos);
        i = 0;
        while(i < data->num_philos + 1)
                pthread_join(threads[i++], NULL);
        i = 0;
        pthread_mutex_destroy(data->forks);
        free(data->forks);
        free(data);
        free_list(head);
        free(threads);
        return (0);
}

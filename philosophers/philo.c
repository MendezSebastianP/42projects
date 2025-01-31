/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:27:43 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/31 18:46:09 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void rules_sleep(t_philosopher *philo)
{
        if (philo->id % 2 == 0)
                usleep(philo->data->time_to_eat * 1000);
        if (philo->data->num_philos % 2 == 1)
        {
                if (philo->id == (philo->data->num_philos))
                        usleep(philo->data->time_to_eat * 1000);
        }
}

void	part1(t_philosopher *philo)
{
	long long now;
	struct timeval time_t;
	
	pthread_mutex_lock(philo->right_fork);
	gettimeofday(&time_t, NULL);
	now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
	if (philo->data->is_dead == 0)
		printf("%lld %d has taken a fork\n", (now - philo->data->start_time)/1000, philo->id);
	pthread_mutex_lock(philo->left_fork);
}

void part2(t_philosopher *philo)
{
	long long now;
	struct timeval time_t;
	
	pthread_mutex_lock(philo->left_fork);
	gettimeofday(&time_t, NULL);
	now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
	if (philo->data->is_dead == 0)
		printf("%lld %d has taken a fork\n",
		(now - philo->data->start_time)/1000, philo->id);
}

void    *action(void *arg)
{
	t_philosopher *philo;

	philo = (t_philosopher *)arg;
	rules_sleep(philo);
	while (1)
	{
		if (philo->id % 2 == 1)
		{
			part2(philo);
			if (philo->data->num_philos == 1)
				return (NULL);
			pthread_mutex_lock(philo->right_fork);
		}
		else
			part1(philo);
		eat(philo);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		if (philo->meals_eaten == philo->data->meals_required
			| ph_sleep(philo) == -1 | think(philo) == -1)
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
        (free(data->forks), free(data), free_list(head), free(threads));
        return (0);
}

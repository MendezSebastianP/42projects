/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:54:41 by smendez-          #+#    #+#             */
/*   Updated: 2025/02/12 10:58:48 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	rules_sleep(t_philosopher *philo)
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
	long long		now;
	struct timeval	time_t;

	pthread_mutex_lock(philo->right_fork);
	gettimeofday(&time_t, NULL);
	now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
	if (philo->data->is_dead == 0)
	{
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("%lld %d has taken a fork\n", (now - philo->data->start_time)
			/ 1000, philo->id);
		pthread_mutex_unlock(&philo->data->print_mutex);
	}
	pthread_mutex_lock(philo->left_fork);
}

void	part2(t_philosopher *philo)
{
	long long		now;
	struct timeval	time_t;

	pthread_mutex_lock(philo->left_fork);
	gettimeofday(&time_t, NULL);
	now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
	if (philo->data->is_dead == 0)
	{
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("%lld %d has taken a fork\n",
			(now - philo->data->start_time) / 1000, philo->id);
		pthread_mutex_unlock(&philo->data->print_mutex);
	}
}

void	*action(void *arg)
{
	t_philosopher	*philo;

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
		if (philo->meals_eaten == philo->data->meals_required || ph_sleep(philo)
			== -1 || think(philo) == -1)
			return (NULL);
	}
	return (NULL);
}

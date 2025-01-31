/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:07:48 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/31 18:26:56 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_philosopher *philo)
{
	struct timeval	time_t;
	long long		now;

	if (philo->data->is_dead == 1)
		return (-1);
	gettimeofday(&time_t, NULL);
	now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
	philo->meals_eaten++;
	philo->last_meal = now;
	printf("%lld %d is eating\n", (now - philo->data->start_time) / 1000,
		philo->id);
	usleep(philo->data->time_to_eat * 1000);
	return (0);
}

int	ph_sleep(t_philosopher *philo)
{
	struct timeval	time_t;
	long long		now;

	if (philo->data->is_dead == 1)
		return (-1);
	gettimeofday(&time_t, NULL);
	now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
	printf("%lld %d is sleeping\n", (now - philo->data->start_time) / 1000,
		philo->id);
	usleep(philo->data->time_to_sleep * 1000);
	return (0);
}

int	think(t_philosopher *philo)
{
	struct timeval	time_t;
	long long		now;
	int				eat;
	int				sleep;

	if (philo->data->is_dead == 1)
		return (-1);
	eat = philo->data->time_to_eat;
	sleep = philo->data->time_to_sleep;
	gettimeofday(&time_t, NULL);
	now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
	printf("%lld %d is thinking\n", (now - philo->data->start_time) / 1000,
		philo->id);
	if (philo->data->num_philos % 2 == 1)
		usleep(500);
	return (0);
}

char	*l1(t_list *philo, long long now)
{
	printf("%lld %d died\n", (now - philo->philo->data->start_time)
		/ 1000, philo->philo->id);
	philo->philo->data->is_dead = 1;
	return (NULL);
}

void	*monitor(void *arg)
{
	int				i;
	t_list			*philo;
	t_list			*head;
	struct timeval	time_t;
	long long		now;

	head = (t_list *)arg;
	i = 0;
	while (1)
	{
		(gettimeofday(&time_t, NULL), philo = head);
		now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
		if (i == (philo->philo->data->meals_required
				* philo->philo->data->num_philos))
			return (NULL);
		i = 0;
		while (philo)
		{
			i = philo->philo->meals_eaten + i;
			if (philo->philo->last_meal + (philo->philo->data->time_to_die
					* 1000) < now)
			return (l1(philo, now));
			philo = philo->next;
		}
	}
}

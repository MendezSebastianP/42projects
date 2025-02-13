/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:07:48 by smendez-          #+#    #+#             */
/*   Updated: 2025/02/13 11:52:38 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_philosopher *philo)
{
	struct timeval	time_t;
	long long		now;
	int			isd;

	pthread_mutex_lock(&philo->data->d);
	isd = philo->data->is_dead;
	pthread_mutex_unlock(&philo->data->d);
	if (isd == 1)
		return (-1);
	gettimeofday(&time_t, NULL);
	now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
	pthread_mutex_lock(&philo->data->me);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->me);
	pthread_mutex_lock(&philo->data->lm);
	philo->last_meal = now;
	pthread_mutex_unlock(&philo->data->lm);
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%lld %d has taken a fork\n",
		(now - philo->data->start_time) / 1000, philo->id);
	printf("%lld %d is eating\n", (now - philo->data->start_time) / 1000,
		philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	usleep(philo->data->time_to_eat * 1000);
	return (0);
}

int	ph_sleep(t_philosopher *philo)
{
	struct timeval	time_t;
	long long		now;
	int			isd;

	pthread_mutex_lock(&philo->data->d);
	isd = philo->data->is_dead;
	pthread_mutex_unlock(&philo->data->d);
	if (isd == 1)
		return (-1);
	gettimeofday(&time_t, NULL);
	now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%lld %d is sleeping\n", (now - philo->data->start_time) / 1000,
		philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	usleep(philo->data->time_to_sleep * 1000);
	return (0);
}

int	think(t_philosopher *philo)
{
	struct timeval	time_t;
	long long		now;
	int			isd;

	pthread_mutex_lock(&philo->data->d);
	isd = philo->data->is_dead;
	pthread_mutex_unlock(&philo->data->d);
	if (isd == 1)
		return (-1);
	gettimeofday(&time_t, NULL);
	now = (time_t.tv_sec * 1000000) + time_t.tv_usec;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%lld %d is thinking\n", (now - philo->data->start_time) / 1000,
		philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	if (philo->data->num_philos % 2 == 1)
		usleep(1000);
	return (0);
}

char	*l1(t_list *philo, long long now, int *i)
{
	while (philo)
	{
		pthread_mutex_lock(&philo->philo->data->me);
		*i = philo->philo->meals_eaten + *i;
		pthread_mutex_unlock(&philo->philo->data->me);
		pthread_mutex_lock(&philo->philo->data->lm);
		if (philo->philo->last_meal + (philo->philo->data->time_to_die * 1000) < now)
		{
			pthread_mutex_unlock(&philo->philo->data->lm);
			pthread_mutex_lock(&philo->philo->data->print_mutex);
			printf("%lld %d died\n", (now - philo->philo->data->start_time)
				/ 1000, philo->philo->id);
			pthread_mutex_unlock(&philo->philo->data->print_mutex);
			pthread_mutex_lock(&philo->philo->data->d);
			philo->philo->data->is_dead = 1;
			pthread_mutex_unlock(&philo->philo->data->d);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->philo->data->lm);
		philo = philo->next;
	}
	return ("continue");
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
		if (i == (philo->philo->data->meals_required2
				* philo->philo->data->num_philos2))
			return (NULL);
		i = 0;
		if (!l1(philo, now, &i))
			return (NULL);
	}
}

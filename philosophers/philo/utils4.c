/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:27:19 by smendez-          #+#    #+#             */
/*   Updated: 2025/02/12 15:24:28 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_data(int argc, char **argv, t_data *data)
{
	struct timeval	time_t;
	int				i;

	i = 0;
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->is_dead = 0;
	if (argc == 6)
		data->meals_required = ft_atoi(argv[5]);
	else
		data->meals_required = -1;
	gettimeofday(&time_t, NULL);
	data->start_time = (time_t.tv_sec * 1000000) + time_t.tv_usec;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
		return (1);
	while (i < data->num_philos)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	return (0);
}

int	ft_atoi(const char *s)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] == 32 || (s[i] > 8 && s[i] < 14))
		i++;
	while ((s[i] < 48 || s[i] > 57) && s[i] != '\0')
	{
		if (s[i] == 45 && s[i + 1] != 43 && j < 1)
			j++;
		else if (s[i] != 43 || s[i + 1] == 43 || s[i + 1] == 45)
			return (0);
		i++;
	}
	while (s[i] > 47 && s[i] < 58)
	{
		k = k * 10 + s[i] - 48;
		i++;
	}
	if (j == 1)
		return (k * -1);
	return (k);
}

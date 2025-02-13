/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:27:43 by smendez-          #+#    #+#             */
/*   Updated: 2025/02/13 12:51:37 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init1(t_data **data, pthread_t **threads, int argc, char **argv)
{
	if (is_valid(argc, argv) == 0)
		return (write(1, "Wrong input\n", 13), 1);
	*data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (start_data(argc, argv, *data) == 1)
		return (1);
	*threads = malloc(sizeof(pthread_t) * ((*data)->num_philos + 1));
	if (!threads)
		return (1);
	return (0);
}

pthread_t	*th_cr(t_list *philos, pthread_t	*threads)
{
	int			i;
	int			n_philos;
	t_list		*head;

	i = 0;
	head = philos;
	n_philos = philos->philo->data->num_philos;
	while (i < n_philos)
	{
		pthread_create(&threads[i], NULL, action, philos->philo);
		philos = philos->next;
		i++;
	}
	philos = head;
	pthread_create(&threads[i], NULL, monitor, philos);
	return (threads);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	t_list		*philos;
	pthread_t	*threads;
	int			i;

	i = 0;
	if (init1(&data, &threads, argc, argv) == 1)
		return (1);
	philos = start_philos(argv, data, 1);
	if (!philos)
		return (free(data->forks), free(data), 1);
	threads = th_cr(philos, threads);
	while (i < data->num_philos + 1)
		pthread_join(threads[i++], NULL);
	pthread_mutex_destroy(data->forks);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->d);
	pthread_mutex_destroy(&data->me);
	pthread_mutex_destroy(&data->lm);
	(free(data->forks), free(data), free_list(philos), free(threads));
	return (0);
}

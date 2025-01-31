/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:27:43 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/31 19:17:07 by smendez-         ###   ########.fr       */
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
	start_data(argc, argv, *data);
	*threads = malloc(sizeof(pthread_t) * ((*data)->num_philos + 1));
	if (!threads)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	t_list		*philos;
	t_list		*head;
	pthread_t	*threads;
	int			i;

	i = 0;
	if (init1(&data, &threads, argc, argv) == 1)
		return (1);
	philos = start_philos(argv, data, 1);
	head = philos;
	while (i < data->num_philos)
	{
		pthread_create(&threads[i], NULL, action, philos->philo);
		philos = philos->next;
		i++;
	}
	philos = head;
	pthread_create(&threads[i], NULL, monitor, philos);
	i = 0;
	while (i < data->num_philos + 1)
		pthread_join(threads[i++], NULL);
	pthread_mutex_destroy(data->forks);
	(free(data->forks), free(data), free_list(head), free(threads));
	return (0);
}

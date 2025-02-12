/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:22:11 by smendez-          #+#    #+#             */
/*   Updated: 2025/02/12 10:38:51 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (*lst == NULL)
	{
		if (new == NULL)
			return ;
		new->next = *lst;
		*lst = new;
		return ;
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	if (n == NULL)
		return (NULL);
	n->philo = content;
	n->next = NULL;
	return (n);
}

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

t_philosopher	*start_p(int id, t_data *data)
{
	t_philosopher	*philo;

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

t_list	*start_philos(char **argv, t_data *data, int i)
{
	int				n_ph;
	t_list			*ph_list;
	t_list			*temp;
	t_philosopher	*philo;
	t_philosopher	*philo_last;

	ph_list = NULL;
	n_ph = atoi(argv[1]);
	while (i <= n_ph)
	{
		philo = start_p(i, data);
		temp = ft_lstnew(philo);
		ft_lstadd_back(&ph_list, temp);
		philo_last = philo;
		i++;
	}
	ph_list->philo->left_fork = philo_last->right_fork;
	return (ph_list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:27:43 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/29 15:42:18 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philosopher   *start_p(int id)
{
        t_philosopher *philo;

        philo->id = id;
        philo->meals_eaten = 0;
        philo->last_meal = 0;
        return (philo);
}

t_list **start_philos(char **argv)
{
        int     i;
        int     n_ph;
        t_list **ph_list;
        t_list *temp;
        

        i = 1;
        ph_list = NULL;
        n_ph = atoi(argv[1]);
        while (i < n_ph)
        {
                temp = ft_lstnew(start_p(i));
                ft_lstadd_back(ph_list, temp);
                i++;
        }
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
        printf("sec: %ld\n", time_t.tv_sec);
        printf("microsec: %ld\n", time_t.tv_usec);
        printf("Size of long: %zu bytes\n", sizeof(long));
        sec = (time_t.tv_sec * 1000000) + time_t.tv_usec;
        printf("sec long: %lld\n", sec);
}

int     main(int argc, char **argv)
{
        t_data data;
        t_list **philos;

        //data = malloc(sizeof(t_data));
        if (is_valid(argc, argv) == 0)
                return (printf("Result: %d", is_valid(argc, argv)));
        printf("start\n");
        philos = start_philos(argv);
        printf("flag1\n");
        start_data(argc, argv, &data);
        printf("flag2\n");
        return (0);
}

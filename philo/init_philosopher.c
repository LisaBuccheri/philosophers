/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:48:22 by lbuccher          #+#    #+#             */
/*   Updated: 2022/03/11 17:48:23 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos_struct(int argc, char **argv, t_philos_data *philo)
{
	philo->mutex = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (!philo->mutex)
		return ;
	philo->is_dead = 0;
	philo->nb_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->start_time = get_time();
	philo->start = 0;
	philo->nb_eat = 0;
	philo->end_meal = 0;
	if (argc == 6)
		philo->nb_philo_must_eat = ft_atoi(argv[5]) * ft_atoi(argv[1]);
	else
		philo->nb_philo_must_eat = -1;
}

void	init_philo_struct(t_philo *philo, t_philos_data *philos, int id)
{
	philo->eat_time = philos->start_time;
	philo->id = id;
	philo->philos_data = philos;
}

void	init_philo_thread(char **ar, t_philos_data *philo_data, t_philo **philo)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&philo_data->the_mut, NULL) != 0)
	{
		printf("Error mutex init\n");
		return ;
	}
	while (++i < ft_atoi(ar[1]))
	{
		philo[i] = malloc(sizeof(t_philo));
		if (!philo[i])
			return ;
		init_philo_struct(philo[i], philo_data, i);
		if (pthread_create(&philo[i]->philo_thrd, NULL, &start, philo[i]) != 0)
		{
			printf("Error pthread creation\n");
			return ;
		}
	}
	philo_data->start = 1;
	philo_data->start_time = get_time();
}

void	init_philo(char **argv, t_philos_data *philos_data, t_philo **philo)
{
	int	i;

	i = -1;
	init_philo_thread(argv, philos_data, philo);
	while (1)
	{
		if (philos_data->nb_eat == philos_data->nb_philo_must_eat)
		{
			philos_data->end_meal = 1;
			pthread_mutex_lock(&philos_data->the_mut);
			break ;
		}
		++i;
		if ((get_time() - philo[i]->eat_time) > philos_data->time_to_die)
		{
			philos_data->is_dead = 1;
			is_doing("%d %ld died\n", philo[i], philos_data->start_time, 1);
			pthread_mutex_lock(&philos_data->the_mut);
			break ;
		}
		else if (i == philo[i]->philos_data->nb_philo - 1)
			i = -1;
	}
	end_philo_thread(philos_data, philo);
}

void	end_philo_thread(t_philos_data *philos_data, t_philo **philo)
{
	int	i;

	i = -1;
	pthread_mutex_unlock(&philos_data->the_mut);
	while (++i < philos_data->nb_philo)
	{
		if (pthread_join(philo[i]->philo_thrd, NULL) != 0)
		{
			printf("Error pthread join\n");
			return ;
		}
	}
	i = -1;
	while (++i < philos_data->nb_philo)
	{
		if (pthread_mutex_destroy(&philos_data->mutex[i]) != 0)
		{
			printf("Error mutex destroy\n");
			return ;
		}
		free(philo[i]);
	}
	free(philo);
}

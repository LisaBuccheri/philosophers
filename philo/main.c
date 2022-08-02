/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:22:56 by lbuccher          #+#    #+#             */
/*   Updated: 2022/03/02 17:24:40 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_doing(char *str, t_philo *philo, useconds_t time, int is_dead)
{
	useconds_t	time_spend;

	if (philo->philos_data->nb_philo_must_eat != -1)
		if (philo->philos_data->nb_eat >= philo->philos_data->nb_philo_must_eat)
			return ;
	pthread_mutex_lock(&philo->philos_data->the_mut);
	time_spend = get_time() - time;
	if (!is_dead && !philo->philos_data->is_dead
		&& !philo->philos_data->end_meal && philo->philos_data->start)
		printf(str, time_spend, philo->id + 1);
	else if (is_dead)
		printf(str, time_spend, philo->id + 1);
	pthread_mutex_unlock(&philo->philos_data->the_mut);
}

void	live(t_philo *philo)
{
	t_philos_data	*data;

	data = philo->philos_data;
	if (data->nb_philo == 1)
		is_doing("%d %ld has taken a fork\n", philo, data->start_time, 0);
	ft_sleep(!(philo->id % 2) * philo->philos_data->time_to_eat / 2);
	while (!data->is_dead && data->nb_philo > 1 && !data->end_meal)
	{
		pthread_mutex_lock(&data->mutex[philo->id]);
		is_doing("%d %ld has taken a fork\n", philo, data->start_time, 0);
		pthread_mutex_lock(&data->mutex[(philo->id + 1) % data->nb_philo]);
		is_doing("%d %ld has taken a fork\n", philo, data->start_time, 0);
		is_doing("%d %ld is eating\n", philo, data->start_time, 0);
		philo->eat_time = get_time();
		data->nb_eat ++;
		ft_sleep(philo->philos_data->time_to_eat);
		is_doing("%d %ld is sleeping\n", philo, data->start_time, 0);
		pthread_mutex_unlock(&data->mutex[philo->id]);
		pthread_mutex_unlock(&data->mutex[(philo->id + 1) % data->nb_philo]);
		ft_sleep(philo->philos_data->time_to_sleep);
		is_doing("%d %ld is thinking\n", philo, data->start_time, 0);
	}
}

void	*start(void *arg)
{
	t_philo	*data;

	data = (t_philo *)arg;
	if (pthread_mutex_init(&data->philos_data->mutex[data->id], NULL) != 0)
	{
		printf("Error mutex %d init\n", data->id);
		return (NULL);
	}
	while (data->philos_data->start == 0)
		;
	data->eat_time = get_time();
	live(data);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_philos_data	*philos_data;
	t_philo			**philo;

	if (ft_error(argc, argv))
		return (1);
	philos_data = malloc(sizeof(t_philos_data));
	if (!philos_data)
		return (write(2, "memory failed\n", 14));
	philo = malloc(sizeof(t_philo *) * ft_atoi(argv[1]));
	if (!philo)
		return (write(2, "memory failed\n", 14));
	init_philos_struct(argc, argv, philos_data);
	init_philo(argv, philos_data, philo);
	pthread_mutex_destroy(&philos_data->the_mut);
	free(philos_data->mutex);
	free(philos_data);
	return (0);
}

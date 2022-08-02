/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:07:56 by lbuccher          #+#    #+#             */
/*   Updated: 2022/03/15 15:08:08 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//tv_sec it's the number of seconds since the epoch
//tv_usec it's additional microseconds after number of seconds calculation since
//the epoch

useconds_t	get_time(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

int	ft_sleep(useconds_t stop_time)
{
	useconds_t	start_time;
	useconds_t	update_time;

	start_time = get_time();
	update_time = start_time;
	while (update_time - start_time < stop_time)
	{
		if (usleep(stop_time) == -1)
			return (-1);
		update_time = get_time();
	}
	return (0);
}

int	ft_error(int argc, char **argv)
{
	int	i;

	if (ft_atoi(argv[1]) == 0)
	{
		printf("Wrong argument\n");
		printf("No philo to live\n");
		return (1);
	}
	i = 0;
	while (++i < argc)
	{
		if ((argc != 5 && argc != 6) || (ft_atoi(argv[i]) < 0) ||
		(ft_atoi(argv[i]) > 2147483647) || (is_digit(argv[i]) == 0))
		{
			printf("Wrong argument\n");
			printf("./philo [nb_philo] [time_to_die] [time_to_eat] ");
			printf("[time_to_sleep] [must_eat]\n");
			return (1);
		}
	}
	return (0);
}

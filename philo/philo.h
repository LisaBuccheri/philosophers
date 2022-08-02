/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:31:35 by lbuccher          #+#    #+#             */
/*   Updated: 2022/03/02 17:36:11 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philos_data	t_philos_data;
typedef struct s_philo			t_philo;

struct s_philos_data
{
	pthread_mutex_t	*mutex;
	pthread_mutex_t	the_mut;
	int				is_dead;
	int				nb_philo;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	useconds_t		start_time;
	int				nb_philo_must_eat;
	int				start;
	int				nb_eat;
	int				end_meal;
};

struct s_philo
{
	pthread_t		philo_thrd;
	long long		eat_time;
	int				id;
	t_philos_data	*philos_data;
};

int			is_digit(char *str);
int			ft_atoi(const char *str);
int			ft_error(int argc, char **argv);
int			ft_sleep(useconds_t stop_time);

useconds_t	get_time(void);

void		*start(void *arg);
void		init_philos_struct(int argc, char **argv, t_philos_data *philo);
void		init_philo_struct(t_philo *philo, t_philos_data *philos, int id);
void		init_philo(char **argv, t_philos_data *philos, t_philo **philo);
void		init_philo_thread(char **ar, t_philos_data *phi_dt, t_philo **phi);
void		end_philo_thread(t_philos_data *philos_data, t_philo **philo);
void		live(t_philo *philo);
void		is_doing(char *str, t_philo *philo, useconds_t time, int is_dead);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:30:32 by oait-bad          #+#    #+#             */
/*   Updated: 2023/06/19 11:52:14 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_philo
{
	int						id;
	int						nb_eat;
	size_t					time_to_die;
	size_t					time_to_eat;
	size_t					time_to_sleep;
	int						nb_philo;
	int						nb_eat_max;
	int						last_eat;
	size_t					start_time;
	pthread_t				*thread;
	pthread_mutex_t			*forks;
	pthread_mutex_t			*mutex;
	pthread_mutex_t			*print;
}					t_philo;

int		ft_atoi(const char *str);
void	*action(void *arg);
void	init_all(t_philo *philo, char **argv);
void	init_mutex(t_philo *philo);
void	init_philo(t_philo *philo);
void	init_args(t_philo *philo, char **argv);
size_t	get_time(size_t start);
void	start_threads(t_philo *philo);
void	ft_usleep(size_t time);

#endif
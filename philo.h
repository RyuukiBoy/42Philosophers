/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:30:32 by oait-bad          #+#    #+#             */
/*   Updated: 2023/06/23 13:11:46 by oait-bad         ###   ########.fr       */
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

typedef struct s_args
{
	int						nb_philo;
	size_t					time_to_die;
	size_t					time_to_eat;
	pthread_mutex_t			print;
	size_t					time_to_sleep;
	int						nb_eat_max;
}					t_args;

typedef struct s_philo
{
	t_args					*args;
	int						id;
	int						nb_eat;
	size_t					last_eat;
	size_t					start_time;
	pthread_t				thread;
	pthread_t				death;
	pthread_mutex_t			last_eat_mutex;
	pthread_mutex_t			*forks;
}					t_philo;

int		ft_atoi(const char *str);
void	*action(void *arg);
void	init_all(t_philo *philo, t_args *args, char **argv);
size_t	get_time(void);
void	start_threads(t_philo *philo);
void	ft_usleep(size_t time);
int		check_death(void *arg);
void	printer(t_philo *philo, char *str);
int		check_eat(t_philo *philo);
int		ft_isdigit(int c);

#endif
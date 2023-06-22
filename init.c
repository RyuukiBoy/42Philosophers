/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:08:57 by oait-bad          #+#    #+#             */
/*   Updated: 2023/06/22 21:08:57 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(t_args *args, char **argv)
{
	args->nb_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->nb_eat_max = -1;
	if (argv[5])
		args->nb_eat_max = ft_atoi(argv[5]);
}

void	init_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->args->nb_philo)
	{
		pthread_mutex_init(&philo->forks[i], NULL);
		i++;
	}
}

void	init_philo(t_philo *philo, t_args *args)
{
	int	i;
	pthread_mutex_t			*forks;

	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* args->nb_philo);
	i = 0;
	while (i < args->nb_philo)
	{
		philo[i].forks = forks;
		philo[i].args = args;
		philo[i].id = i + 1;
		//philo[i].last_eat = get_time();
		philo[i].start_time = get_time();
		philo[i].nb_eat = 0;
		i++;
	}
}

void	init_all(t_philo *philo, t_args *args, char **argv)
{
	init_args(args, argv);
	init_philo(philo, args);
	init_mutex(philo);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:50:55 by marvin            #+#    #+#             */
/*   Updated: 2023/06/14 17:50:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(t_philo *philo, char **argv)
{
	philo->nb_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->nb_eat_max = -1;
	if (argv[5])
		philo->nb_eat_max = ft_atoi(argv[5]);
}

void	init_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	philo->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* philo->nb_philo);
	while (i < philo->nb_philo)
	{
		pthread_mutex_init(&philo->forks[i], NULL);
		i++;
	}
}

void	init_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		philo->id = i + 1;
		philo->last_eat = get_time(philo->start_time);
		philo->nb_eat = 0;
		i++;
	}
}

void	init_all(t_philo *philo, char **argv)
{
	init_args(philo, argv);
	init_mutex(philo);
	init_philo(philo);
}

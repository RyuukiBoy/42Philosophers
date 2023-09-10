/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:08:10 by oait-bad          #+#    #+#             */
/*   Updated: 2023/06/27 08:33:42 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->id - 1]);
	printer(philo, "has taken fork\n");
	pthread_mutex_lock(&philo->forks[philo->id % philo->args->nb_philo]);
	printer(philo, "has taken fork\n");
	printer(philo, "is eating\n");
	pthread_mutex_lock(&philo->last_eat_mutex);
	philo->last_eat = get_time();
	ft_usleep(philo->args->time_to_eat);
	philo->nb_eat++;
	pthread_mutex_unlock(&philo->last_eat_mutex);
	pthread_mutex_unlock(&philo->forks[philo->id - 1]);
	pthread_mutex_unlock(&philo->forks[philo->id % philo->args->nb_philo]);
}

void	sleeping(t_philo *philo)
{
	printer(philo, "is sleeping\n");
	ft_usleep(philo->args->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	printer(philo, "is thinking\n");
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		if (check_eat(philo))
			break ;
	}
	return (NULL);
}

void	start_threads(t_philo *philo)
{
	int			i;

	i = 0;
	while (i < philo->args->nb_philo)
	{
		pthread_create(&philo[i].thread, NULL, philo_life, &philo[i]);
		usleep(50);
		i++;
	}
}

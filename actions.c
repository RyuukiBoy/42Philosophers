/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:03:54 by oait-bad          #+#    #+#             */
/*   Updated: 2023/06/19 12:15:19 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eating(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->forks[philo->id - 1]);
	printf("%ld philo %d has taken left fork\n", get_time(philo->start_time), philo->id);
	pthread_mutex_lock(&philo->forks[philo->id % philo->nb_philo]);
	printf("%ld philo %d has taken right fork\n", get_time(philo->start_time), philo->id);
	printf("%ld philo %d is eating\n", get_time(philo->start_time), philo->id);
	philo->last_eat = get_time(philo->start_time);
	ft_usleep(philo->time_to_eat);
	philo->nb_eat++;
	pthread_mutex_unlock(&philo->forks[philo->id - 1]);
	pthread_mutex_unlock(&philo->forks[philo->id % philo->nb_philo]);
	return (NULL);
}

void	*sleeping(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("%ld philo %d is sleeping\n", get_time(philo->start_time), philo->id);
	ft_usleep(philo->time_to_sleep);
	return (NULL);
}

void	*thinking(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("%ld philo %d is thinking\n", get_time(philo->start_time), philo->id);
	return (NULL);
}

void	*check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (get_time(philo->start_time) - philo->last_eat > philo->time_to_die)
		{
			pthread_mutex_lock(philo->print);
			printf("%ld philo %d died\n", get_time(philo->start_time), philo->id);
			pthread_mutex_unlock(philo->print);
			exit(1);
		}
	}
	return (NULL);
}



void	*check_nb_eat(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	i = 0;
	while (i < philo->nb_philo)
	{
		if (philo->nb_eat < philo->nb_eat_max)
			return (NULL);
		i++;
	}
	pthread_mutex_unlock(philo->print);
	return (NULL);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;
	pthread_t	tid;

	philo = (t_philo *)arg;
	pthread_create(&tid, NULL, check_death, philo);
	pthread_detach(tid);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		if (philo->nb_eat_max != -1)
			check_nb_eat(philo);
	}
	return (NULL);
}

void	start_threads(t_philo *philo)
{
	int			i;
	pthread_t	tid;

	i = 0;
	while (i < philo->nb_philo)
	{
		pthread_create(&tid, NULL, philo_life, &philo[i]);
		pthread_detach(tid);
		usleep(100);
		i++;
	}
	pthread_create(&tid, NULL, check_nb_eat, philo);
	pthread_detach(tid);
}

int		main(int ac, char **av)
{
	t_philo	philo;

	if (ac < 5 || ac > 6)
		return (printf("Error: bad arguments\n"));
	init_all(&philo, av);
	start_threads(&philo);
	return (0);
}
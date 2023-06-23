/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:08:23 by oait-bad          #+#    #+#             */
/*   Updated: 2023/06/23 18:52:53 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->nb_eat >= philo->args->nb_eat_max)
			return (1);
		pthread_mutex_lock(&philo->last_eat_mutex);
		if (get_time() - philo->last_eat > philo->args->time_to_die)
		{
			printer(philo, "is dead\n");
			return (1);
		}
		pthread_mutex_unlock(&philo->last_eat_mutex);
	}
	return (0);
}

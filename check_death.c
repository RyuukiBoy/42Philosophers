/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:08:23 by oait-bad          #+#    #+#             */
/*   Updated: 2023/06/22 21:08:24 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

void	*check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (get_time() - philo->last_eat > philo->args->time_to_die)
		{
			pthread_mutex_lock(philo->print);
			printer(philo, "died");
			pthread_mutex_unlock(philo->print);
			return (NULL);
		}
	}
	return (NULL);
}

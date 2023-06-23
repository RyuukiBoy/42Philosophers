/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:08:23 by oait-bad          #+#    #+#             */
/*   Updated: 2023/06/23 01:50:43 by marvin           ###   ########.fr       */
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
			printer(philo, "is dead\n", 0);
			exit (0);
		}
	}
	return (NULL);
}

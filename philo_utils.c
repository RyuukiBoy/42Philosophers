/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:09:06 by oait-bad          #+#    #+#             */
/*   Updated: 2023/06/22 21:09:06 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t time)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	printer(t_philo *philo, char *str, int dead)
{
	pthread_mutex_lock(&philo->args->print);
	printf("%ld ms philo %d %s", get_time() - philo->start_time, philo->id, str);
	if (dead)
		pthread_mutex_unlock(&philo->args->print);
}

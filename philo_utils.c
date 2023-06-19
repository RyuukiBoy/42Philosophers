/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utlis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:54:45 by marvin            #+#    #+#             */
/*   Updated: 2023/06/16 14:54:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(size_t start)
{
	struct timeval	time;
	size_t			now;

	gettimeofday(&time, NULL);
	now = (time.tv_sec * 1000) + (time.tv_usec / 1000) - start;
	return (now);
}

void	ft_usleep(size_t time)
{
	size_t	start;

	start = get_time(0);
	while (get_time(start) < time)
		usleep(100);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:09:13 by oait-bad          #+#    #+#             */
/*   Updated: 2023/06/26 20:53:03 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_args		*args;

	if (argc < 5 || argc > 6)
		return (printf("Error: bad arguments\n"));
	if (check_num_args(argv))
		return (printf("Error: bad arguments\n"));
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	args = malloc(sizeof(t_args));
	init_all(philo, args, argv);
	start_threads(philo);
	while (1)
	{
		if (check_death(philo))
			break ;
	}
}

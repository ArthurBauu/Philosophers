/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:24:58 by arbaudou          #+#    #+#             */
/*   Updated: 2025/03/31 17:14:03 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int print_params(t_params *params)
{
	printf("nb_philo: %zu\n", params->nb_philo);
	printf("time_to_die: %zu\n", params->time_to_die);
	printf("time_to_eat: %zu\n", params->time_to_eat);
	printf("time_to_sleep: %zu\n", params->time_to_sleep);
	printf("nb_must_eat: %zu\n", params->nb_must_eat);
	printf("start_time: %zu\n", params->start_time);
	printf("status_dead: %d\n", params->status_dead);
	return (0);
}

int print_philo(t_philo **philo)
{	
	int i ; 

	i = 0;
	while (philo[i])
	{
		printf("philo numero : %d\n", philo[i]->id);
		printf("philo last meal : %d\n", philo[i]->since_last_meal);
		printf("philo nbmeal : %d\n", philo[i]->nb_meal);
		i++;
	}
	return (0);
}
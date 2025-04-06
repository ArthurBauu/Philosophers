/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:24:58 by arbaudou          #+#    #+#             */
/*   Updated: 2025/04/06 01:26:28 by arbaudou         ###   ########.fr       */
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
		printf("philo numero : %ld\n", philo[i]->id);
		printf("philo last meal : %ld\n", philo[i]->since_last_meal);
		printf("philo nbmeal : %ld\n", philo[i]->nb_meal);
		i++;
	}
	return (0);
}
void print_state(t_philo *philo, char *str, size_t time)
{
	if (mut_end(philo->params) && str[0] != 'd')
		return ;
	pthread_mutex_lock(&philo->params->print);
	printf("%zu %ld %s\n", time, philo->id + 1, str);
	pthread_mutex_unlock(&philo->params->print);
}
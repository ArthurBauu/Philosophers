/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mut_eat_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:49:55 by arbaudou          #+#    #+#             */
/*   Updated: 2025/04/05 23:46:46 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t get_eat_count(t_philo *philo)
{
	size_t count;

	pthread_mutex_lock(&philo->lock_c_meal);
	count = philo->nb_meal;
	pthread_mutex_unlock(&philo->lock_c_meal);
	return (count);
}
void incr_eat_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_c_meal);
	philo->nb_meal++;
	pthread_mutex_unlock(&philo->lock_c_meal);
}
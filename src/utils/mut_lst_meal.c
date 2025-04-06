/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mut_lst_meal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:49:55 by arbaudou          #+#    #+#             */
/*   Updated: 2025/04/05 17:51:00 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t time_last_meal(t_philo *philo)
{
	size_t time;

	pthread_mutex_lock(&philo->lock_last_meal);
	time = philo->since_last_meal;
	pthread_mutex_unlock(&philo->lock_last_meal);
	return (time);
}

void set_time_last_meal(t_philo *philo, size_t time)
{
	pthread_mutex_lock(&philo->lock_last_meal);
	philo->since_last_meal = time;
	pthread_mutex_unlock(&philo->lock_last_meal);
}


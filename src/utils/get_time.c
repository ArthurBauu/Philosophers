/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:24:50 by arbaudou          #+#    #+#             */
/*   Updated: 2025/04/06 00:22:05 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	tv;
	int				time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

size_t get_elapsed_time(t_philo *philo)
{
	size_t time;

	time = get_time() - philo->params->start_time;
	return (time);
}

size_t last_meal_delay(t_philo *philo)
{
	size_t time;
	size_t last_meal;
	size_t delay;

	time = get_time() - philo->params->start_time;
	last_meal = time_last_meal(philo);
	delay = time - last_meal;
	return (delay);
}


void ft_usleep(size_t time)
{
	size_t start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}
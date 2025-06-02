/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:15:49 by arbaudou          #+#    #+#             */
/*   Updated: 2025/06/02 14:18:20 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	routine_think(t_philo *philo)
{
	if (mut_end(philo->params))
		return (1);
	print_state(philo, THINK, get_elapsed_time(philo));
	ft_usleep(philo->params->time_to_sleep);
	return (0);
}

int	routine_sleep(t_philo *philo)
{
	if (mut_end(philo->params))
		return (1);
	philo_sleep(philo);
	return (0);
}

int	routine_eat(t_philo *philo)
{
	if (mut_end(philo->params))
		return (1);
	philo_eat(philo);
	return (0);
}

int	routine_fork(t_philo *philo)
{
	if (philo->params->nb_philo == 1)
	{
		print_state(philo, FORK, get_elapsed_time(philo));
		ft_usleep(philo->params->time_to_die);
		return (1);
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->params->fork[philo->id]);
		print_state(philo, FORK, get_elapsed_time(philo));
		pthread_mutex_lock(&philo->params->fork[(philo->id + 1)
			% philo->params->nb_philo]);
	}
	else
	{
		pthread_mutex_lock(&philo->params->fork[(philo->id + 1)
			% philo->params->nb_philo]);
		print_state(philo, FORK, get_elapsed_time(philo));
		pthread_mutex_lock(&philo->params->fork[philo->id]);
	}
	return (0);
}

int	routine_release_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->params->fork[philo->id]);
		pthread_mutex_unlock(&philo->params->fork[(philo->id + 1)
			% philo->params->nb_philo]);
	}
	else
	{
		pthread_mutex_unlock(&philo->params->fork[(philo->id + 1)
			% philo->params->nb_philo]);
		pthread_mutex_unlock(&philo->params->fork[philo->id]);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:31:38 by arbaudou          #+#    #+#             */
/*   Updated: 2025/06/02 14:18:42 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_nb_eat(t_env *env)
{
	size_t	i;

	i = 0;
	if (get_eat_count(env->philo[0]) >= env->params->nb_must_eat)
	{
		while (i < env->params->nb_philo)
		{
			if (get_eat_count(env->philo[i]) < env->params->nb_must_eat)
				break ;
			if (i == env->params->nb_philo - 1)
			{
				update_end(env->params, 1);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int	check_time_eat(t_env *env)
{
	size_t	i;
	size_t	time;

	i = 0;
	while (i < env->params->nb_philo)
	{
		if (last_meal_delay(env->philo[i]) > env->params->time_to_die
			&& get_eat_count(env->philo[i]) < env->params->nb_must_eat)
		{
			time = get_elapsed_time(env->philo[i]);
			update_end(env->params, 1);
			usleep(200);
			print_state(env->philo[i], DEAD, time);
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_simulation_ended(t_params *params)
{
	int	status;

	pthread_mutex_lock(&params->dead);
	status = params->status_dead;
	pthread_mutex_unlock(&params->dead);
	return (status);
}

void	philo_sleep(t_philo *philo)
{
	size_t	start_time;
	size_t	elapsed;

	print_state(philo, SLEEP, get_elapsed_time(philo));
	start_time = get_time();
	while (1)
	{
		elapsed = get_time() - start_time;
		if (elapsed >= philo->params->time_to_sleep
			|| is_simulation_ended(philo->params))
			break ;
		usleep(200);
	}
}

void philo_eat(t_philo *philo)
{
    size_t start_time;
    size_t elapsed;

    set_time_last_meal(philo, get_elapsed_time(philo));
    incr_eat_count(philo);
    print_state(philo, EAT, get_elapsed_time(philo));
    start_time = get_time();
    while (1)
    {
        elapsed = get_time() - start_time;
        if (elapsed >= philo->params->time_to_eat
            || is_simulation_ended(philo->params))
            break;
        usleep(200);
    }
}

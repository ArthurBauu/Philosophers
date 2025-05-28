/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:32:12 by arbaudou          #+#    #+#             */
/*   Updated: 2025/05/28 13:17:26 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*monitoring(void *arg)
{
	t_env	*env;

	env = (t_env *)arg;
	while (1)
	{
		if (mut_end(env->params))
			break ;
		if (check_time_eat(env))
			break ;
		if (check_nb_eat(env))
			break ;
		usleep(100);
	}
	return (NULL);
}

int	init(t_env *env)
{
	pthread_create(&env->monitor, NULL, monitoring, env);
	return (0);
}

int	join_threads(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < env->params->nb_philo)
	{
		pthread_join(env->philo[i]->thread, NULL);
		i++;
	}
	pthread_join(env->monitor, NULL);
	return (0);
}

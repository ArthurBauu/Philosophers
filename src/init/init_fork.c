/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:14:54 by arbaudou          #+#    #+#             */
/*   Updated: 2025/03/31 17:19:09 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_fork(t_env *env)
{
	size_t i;

	env->params->fork = malloc(sizeof(pthread_mutex_t) * env->params->nb_philo);
	if (!env->params->fork)
		return (1);
	gc_add(env->gc, env->params->fork);
	i = 0;
	while (i < env->params->nb_philo)
	{
		pthread_mutex_init(&env->params->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&env->params->locked_fork, NULL);
	pthread_mutex_init(&env->params->print, NULL);
	pthread_mutex_init(&env->params->dead, NULL);
	return (0);
}
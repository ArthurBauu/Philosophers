/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:31:33 by arbaudou          #+#    #+#             */
/*   Updated: 2025/04/06 01:37:55 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void free_all(t_env *env)
{
	size_t i;

	i = 0;
	while (i < env->params->nb_philo)
	{
		pthread_mutex_destroy(&env->params->fork[i]);
		pthread_mutex_destroy(&env->philo[i]->lock_c_meal);
		pthread_mutex_destroy(&env->philo[i]->lock_last_meal);
		i++;
	}
	pthread_mutex_destroy(&env->params->print);
	pthread_mutex_destroy(&env->params->dead);
	pthread_mutex_destroy(&env->params->locked_fork);
	gc_free(env->gc);
}

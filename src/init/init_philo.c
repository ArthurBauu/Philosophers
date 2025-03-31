/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:12:02 by arbaudou          #+#    #+#             */
/*   Updated: 2025/03/31 17:11:39 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo *create_philo(t_env *env, int id)
{
	t_philo *philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	gc_add(env->gc, philo);
	philo->id = id;
	printf("philo numero : %d\n", philo->id);
	philo->since_last_meal = 0;
	printf("philo last meal : %d\n", philo->since_last_meal);
	philo->nb_meal = 0;
	printf("philo nbmeal : %d\n", philo->nb_meal);
	philo->params = env->params;
	// print_params(env->params);
	return (philo);
}


int	init_philo(t_env *env)
{
	size_t i;
	
	env->philo = malloc(sizeof(t_philo *) * env->params->nb_philo);
	if (!env->philo)
		return (1);
	gc_add(env->gc, env->philo);
	i = 0;
	while (i < env->params->nb_philo)
	{
		env->philo[i] = create_philo(env, i);
		i+=2;
	}
	i = 1;
	while (i < env->params->nb_philo)
	{
		env->philo[i] = create_philo(env, i);
		i+=2;
	}
	return (0);
}
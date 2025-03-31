/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:56:29 by arbaudou          #+#    #+#             */
/*   Updated: 2025/03/31 17:36:52 by arbaudou         ###   ########.fr       */
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

int	init_param(t_env *env, char **av)
{
	env->params = malloc(sizeof(t_params));
	if (!env->params)
		return (1);
	env->params->nb_philo = ft_atoi(av[1]);
	env->params->time_to_die = ft_atoi(av[2]);
	env->params->time_to_eat = ft_atoi(av[3]);
	env->params->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		env->params->nb_must_eat = ft_atoi(av[5]);
	else
		env->params->nb_must_eat = -1;
	env->params->start_time = get_time();
	env->params->status_dead = 0;
	return (0);
}

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
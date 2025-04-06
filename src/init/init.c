/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:56:29 by arbaudou          #+#    #+#             */
/*   Updated: 2025/04/06 01:43:46 by arbaudou         ###   ########.fr       */
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
	gc_add(env->gc, env->params);
	env->params->nb_philo = ft_atol(av[1]);
	env->params->time_to_die = ft_atol(av[2]);
	env->params->time_to_eat = ft_atol(av[3]);
	env->params->time_to_sleep = ft_atol(av[4]);
	if (av[5])
		env->params->nb_must_eat = ft_atol(av[5]);
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
	philo->id = id;
	philo->since_last_meal = 0;
	philo->nb_meal = 0;
	philo->params = env->params;
	pthread_mutex_init(&philo->lock_c_meal, NULL);
	pthread_mutex_init(&philo->lock_last_meal, NULL);
	pthread_create(&philo->thread, NULL, &routine_check, philo);
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
		if (!env->philo[i])
			return (1);
		gc_add(env->gc, env->philo[i]);
		i+=2;
	}
	i = 1;
	while (i < env->params->nb_philo)
	{
		env->philo[i] = create_philo(env, i);
		if (!env->philo[i])
			return (1);
		gc_add(env->gc, env->philo[i]);
		i+=2;
	}
	return (0);
}
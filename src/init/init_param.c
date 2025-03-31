/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:56:29 by arbaudou          #+#    #+#             */
/*   Updated: 2025/03/31 17:25:40 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
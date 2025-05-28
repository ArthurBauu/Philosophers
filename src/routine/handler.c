/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:56:11 by arbaudou          #+#    #+#             */
/*   Updated: 2025/05/28 13:16:45 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_check(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!mut_end(philo->params))
	{
		if (routine_fork(philo))
			break ;
		if (routine_eat(philo))
		{
			routine_release_fork(philo);
			break ;
		}
		if (routine_release_fork(philo))
			break ;
		if (routine_sleep(philo))
			break ;
		if (philo->params->nb_philo % 2 != 0)
			routine_think(philo);
	}
	return (NULL);
}

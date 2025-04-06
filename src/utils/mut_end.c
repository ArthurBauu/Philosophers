/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mut_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:33:19 by arbaudou          #+#    #+#             */
/*   Updated: 2025/04/05 18:36:16 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int mut_end(t_params *params)
{
	int end;
	
	pthread_mutex_lock(&params->dead);
	end = params->status_dead;
	pthread_mutex_unlock(&params->dead);
	return (end);
}

void update_end(t_params *params, int status)
{
	pthread_mutex_lock(&params->dead);
	params->status_dead = status;
	pthread_mutex_unlock(&params->dead);
}
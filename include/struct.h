/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:50:40 by arbaudou          #+#    #+#             */
/*   Updated: 2025/03/31 17:21:40 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"
# include <pthread.h>

typedef struct s_gc
{
	t_list			*start;
}					t_gc;

typedef struct s_params
{
	size_t			nb_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			nb_must_eat;
	size_t			start_time;
	volatile int	status_dead;
	pthread_mutex_t	*fork;
	pthread_mutex_t	locked_fork;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;

}					t_params;

typedef struct s_philo
{
	int				id;
	int				since_last_meal;
	int				nb_meal;
	pthread_t		thread;
	t_params		*params;
}					t_philo;

typedef struct s_env
{
	t_params		*params;
	t_philo			**philo;
	t_gc			*gc;
	pthread_t		*monitor;
}					t_env;

#endif
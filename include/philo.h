/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:50:13 by arbaudou          #+#    #+#             */
/*   Updated: 2025/06/02 14:19:06 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "struct.h"
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/* DEFINE */

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"

/* INIT */
int		init_param(t_env *env, char **av);
int		init_philo(t_env *env);
int		init_fork(t_env *env);

/* MONITOR */
int		init(t_env *env);
int		join_threads(t_env *env);
void	*routine_check(void *arg);
int		check_nb_eat(t_env *env);
int		check_time_eat(t_env *env);
void	philo_sleep(t_philo *philo);
void	philo_eat(t_philo *philo);

int		routine_eat(t_philo *philo);
int		routine_sleep(t_philo *philo);
int		routine_think(t_philo *philo);
int		routine_fork(t_philo *philo);
int		routine_release_fork(t_philo *philo);

/* UILS */
short	is_int(size_t size, char **arg);
size_t	ft_atol(const char *nptr);
size_t	get_time(void);
int		ft_strlen(char const *s);
size_t	get_eat_count(t_philo *philo);
size_t	last_meal_delay(t_philo *philo);
void	ft_usleep(size_t time);
size_t	get_elapsed_time(t_philo *philo);
void	incr_eat_count(t_philo *philo);
size_t	time_last_meal(t_philo *philo);
void	set_time_last_meal(t_philo *philo, size_t time);
size_t	time_last_meal(t_philo *philo);
void	set_time_last_meal(t_philo *philo, size_t time);
int		mut_end(t_params *params);
void	update_end(t_params *params, int status);
void	free_all(t_env *env);

/* GARBAGE COLECTOR */

t_gc	*gc_init(void);
short	gc_add(t_gc *gc, void *content);
void	gc_free(t_gc *gc);
short	gc_remove_one(t_gc *gc, void *content);

/* PRINT */

int		print_params(t_params *params);
int		print_philo(t_philo **philo);
void	print_state(t_philo *philo, char *str, size_t time);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:50:13 by arbaudou          #+#    #+#             */
/*   Updated: 2025/03/31 17:29:57 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include "struct.h"
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/* INIT */
int		init_param(t_env *env, char **av);
int		init_philo(t_env *env);
int		init_fork(t_env *env);

/* UILS */
short	is_int(size_t size, char **arg);
size_t	get_time(void);

/* GARBAGE COLECTOR */

t_gc	*gc_init(void);
short	gc_add(t_gc *gc, void *content);
void	gc_free(t_gc *gc);
short	gc_remove_one(t_gc *gc, void *content);

/* PRINT */

int		print_params(t_params *params);
int		print_philo(t_philo **philo);

#endif
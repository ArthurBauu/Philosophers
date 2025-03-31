/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:02:29 by arbaudou          #+#    #+#             */
/*   Updated: 2025/03/31 17:33:31 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo(t_env *env, char **av)
{
	if (init_param(env, av))
		return (1);
	if (init_fork(env))
		return (1);
	if (init_philo(env))
		return (1);
	return (0);
}




int main(int ac, char **av)
{
	t_env env;
	
	if ((ac != 5 && ac != 6) || is_int(ac, av))
	{
		write(2,
			"Usage: ./philo [number_of_philosophers]"
			"[time_to_die] [time_to_eat] [time_to_sleep] "
			"[number_of_times_each_philosopher_must_eat (optional)]\n",
			138);
		return (0);
	}
	env.gc = gc_init();
	if (philo(&env, av))
	{
		// clean(&env);
		write(2, "Error\n", 6);
		return (1);
	}
	print_params(env.params);
	print_philo(env.philo);
	// clean(&env);
	return (1);
}
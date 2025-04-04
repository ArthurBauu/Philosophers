/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:05:19 by arbaudou          #+#    #+#             */
/*   Updated: 2025/03/31 16:11:06 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

short	is_int(size_t size, char **arg)
{
	size_t	i;
	char	*str;

	i = 1;
	while (i < size)
	{
		if (ft_strlen(arg[i]) > 12)
			return (1);
		if (ft_atol(arg[i]) > INT_MAX || ft_atol(arg[i]) < 1)
			return (1);
		str = arg[i];
		if (*str == '-' || *str == '+')
			str++;
		while (*str)
		{
			if (*str < '0' || *str > '9')
				return (1);
			str++;
		}
		i++;
	}
	return (0);
}

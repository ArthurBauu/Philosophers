/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:05:19 by arbaudou          #+#    #+#             */
/*   Updated: 2025/04/06 01:43:00 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_atol(const char *nptr)
{
	size_t	i;
	size_t	result;
	size_t	s;

	i = 0;
	result = 0;
	s = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * s);
}

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

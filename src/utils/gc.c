/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_c.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:51:45 by arbaudou          #+#    #+#             */
/*   Updated: 2025/03/28 17:00:54 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_gc	*gc_init(void)
{
	t_gc	*gc;
	
	gc = malloc(sizeof(t_gc));
	if (!gc)
		return (NULL);
	gc->start = NULL;
	return (gc);
}

short	gc_add(t_gc *gc, void *content)
{
	t_list	*new;
	
	new = malloc(sizeof(t_list));
	if (!new)
		return (1);
	new->content = content;
	new->next = gc->start;
	gc->start = new;
	return (0);
}

void	gc_free(t_gc *gc)
{
	t_list	*tmp;
	t_list 	*list;
	
	if (!gc)
		return ;
	tmp = gc->start;
	while (tmp)
	{
		list = tmp;
		tmp = tmp->next;
		free(list->content);
		free(list);
	}
	free(gc);
}	

short gc_remove_one(t_gc *gc, void *content)
{
	t_list	*tmp;
	t_list	*prev;
	
	if (!gc)
		return (1);
	tmp = gc->start;
	prev = NULL;
	while (tmp)
	{
		if (tmp->content == content)
		{
			if (prev)
				prev->next = tmp->next;
			else
				gc->start = tmp->next;
			free(tmp);
			return (0);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (1);
}
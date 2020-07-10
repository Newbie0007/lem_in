/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooming.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 08:30:56 by tngwenya          #+#    #+#             */
/*   Updated: 2018/12/07 16:17:13 by tngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void		build_room(t_farm *farm, int len)
{
	t_room	*new_room;
	t_room	*tmp;

	if (!(new_room = (t_room *)malloc(sizeof(t_room))))
		ft_errors("Error: could not allocate memory for room.");
	farm->num_room++;
	new_room->name = ft_strndup(farm->info, len);
	new_room->link = NULL;
	new_room->next = NULL;
	if (!farm->rooms)
		farm->rooms = new_room;
	else
	{
		tmp = farm->rooms;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_room;
	}
}

t_room		*select_room(char *name, t_room *rooms)
{
	t_room	*tmp;

	tmp = rooms;
	while (tmp)
	{
		if (ft_strequ(name,  tmp->name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:39:48 by tngwenya          #+#    #+#             */
/*   Updated: 2018/11/29 20:22:13 by tngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int			path_finder(char *start_room, char *name, t_path *path)
{
	t_path	*iter;

	iter = path;
	while (iter)
	{
		if (ft_strequ(name, iter->name) || ft_strequ(name, start_room))
			return (0);
		iter = iter->next;
	}
	return (1);
}

int			find_end(t_farm *farm, t_room *cur_room, t_path *path)
{
	t_path	*new_p;
	t_path	*tmp_room;
	t_link	*link;

	if (ft_strequ(cur_room->name, farm->end_room))
		return (1);
	new_p = NULL;
	tmp_room = path;
	link = cur_room->link;
	while (tmp_room->next)
		tmp_room = tmp_room->next;
	while (link)
	{
		if (path_finder(farm->start_room,link->room->name, path))
		{
			if(!(new_p = (t_path *)malloc(sizeof(t_path))))
				ft_errors("Error: cannot allocate memory for path");
			new_p->name = link->room->name;
			new_p->next = NULL;
			tmp_room->next = new_p;
			new_p->last = find_end(farm, link->room, path);
			if (new_p->last)
				return (1);
		}
		link = link->next;
	}
	return (0);
}

t_path		*path_search(t_farm *farm, t_room *start)
{
	int		i;
	t_link	*link;

	i = 0;
	link = start->link;
	while (link)
	{
		if (!(start->paths[i] = (t_path *)malloc(sizeof(t_path))))
			ft_errors("Error: could not allocate memory for path");
		start->paths[i]->name = link->room->name;
		start->paths[i]->next = NULL;
		start->paths[i]->last = find_end(farm, link->room, start->paths[i]);
		if (start->paths[i]->last)
			return (start->paths[i]);
		i++;
		link = link->next;
	}
	return (NULL);
}

t_path		*begin(t_farm *farm)
{
	t_room	*tmp;
	t_link	*links;
	int		size;

	size = 0;
	links = NULL;
	tmp = farm->rooms;
	while (tmp && !ft_strequ(tmp->name, farm->start_room))
		tmp = tmp->next;
	links = tmp->link;
	while (links && ++size)
		links = links->next;
	if (!(tmp->paths = (t_path **)malloc(sizeof(t_path *) + (size + 1))))
		ft_errors("Error: could not allocate memory for path.");
	tmp->paths[size] = NULL;
	return (path_search(farm, tmp));
}


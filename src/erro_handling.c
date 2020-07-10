/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 13:16:59 by tngwenya          #+#    #+#             */
/*   Updated: 2018/11/29 16:12:17 by tngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void			ft_errors(char *msg)
{
	ft_putendl(msg);
	exit(1);
}

static void		start_end_check(t_farm *farm)
{
	if (!farm->start_room || !farm->end_room)
		ft_errors("Error: rooms not provided.");
}

static void		duplicate_check(t_room *rooms)
{
	t_room		*tmp;
	t_room		*iter;

	tmp = rooms;
	while (tmp->next)
	{
		iter = tmp->next;
		if (tmp->name[0] == 'L')
			ft_errors("Error: invalid room name.");
		while (iter)
		{
			if (ft_strequ(tmp->name, iter->name))
				ft_errors("Error: duplicate rooms");
			iter = iter->next;
		}
		tmp = tmp->next;
	}
}

void			proofing(t_farm *farm)
{
	start_end_check(farm);
	duplicate_check(farm->rooms);
}
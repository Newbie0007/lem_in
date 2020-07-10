/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 09:59:02 by tngwenya          #+#    #+#             */
/*   Updated: 2018/11/29 20:06:54 by tngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void		put_link(t_farm *farm, char *src, char *dst)
{
	
	t_link		*new;
	t_link		*tmp_link;
	t_room		*tmp;
	t_room		*tmp2;

	if (!(tmp2 = select_room(dst, farm->rooms)) || !ft_strcmp(src, dst))
		ft_errors(ft_strjoin("Error: no room found ", dst));
	if (!(tmp = select_room(src, farm->rooms)))
		ft_errors(ft_strjoin("Error: no room found ", src));
	if (!(new = (t_link *)malloc(sizeof(t_room))))
		ft_errors("Error: could not allocate memory");
	new->room = tmp2;
	new->next = NULL;
	if (!tmp->link)
		tmp->link = new;
	else
	{
		tmp_link = tmp->link;
		while (tmp_link->next)
			tmp_link = tmp_link->next;
		tmp_link->next = new;
	}
}

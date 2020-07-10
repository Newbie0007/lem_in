/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farming.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 08:40:17 by tngwenya          #+#    #+#             */
/*   Updated: 2018/11/29 14:42:27 by tngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

static t_info	*new_farm(char *info)
{
	t_info *new_data;

	new_data = NULL;
	if (!(new_data = (t_info *)malloc(sizeof(t_farm))))
		ft_errors("Error: could not allocate memory for information reading.");
	new_data->data = ft_strdup(info);
	new_data->next = NULL;
	return (new_data);
}

void			farming(t_farm *farm)
{
	t_info		*seek_f;

	if (farm->file == NULL)
		farm->file = new_farm(farm->info);
	else
	{
		seek_f = farm->file;
		while (seek_f->next)
			seek_f = seek_f->next;
		seek_f->next = new_farm(farm->info);
	}
}	

void		printing(t_info *file)
{
	t_info	*node;

	node = file;
	while (node)
	{
		ft_putendl(node->data);
		node = node->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:39:48 by tngwenya          #+#    #+#             */
/*   Updated: 2018/11/29 19:42:33 by tngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

static void		first_link(t_farm *farm)
{
	char **pipe;

	if (!ft_strchr(farm->info, '-') && farm->info[0] != '#')
		ft_errors("Error: invalid link");
	if (farm->info[0] != '#')
	{
		pipe = ft_strsplit(farm->info, '-');
		put_link(farm, pipe[0], pipe[1]);
		put_link(farm, pipe[1], pipe[0]);
		ft_strings_del(pipe);
	}
	farming(farm);
	free(farm->info);
}

void			anting(t_farm *farm)
{
	if (get_next_line(0, &farm->info) < 1)
		ft_errors("Error: invalid file");
	while (farm->info[0]== '#' && !ft_strequ(farm->info, "##start") &&
			!ft_strequ(farm->info, "##end"))
		get_next_line(0, &farm->info);
	if (!ft_isnumber(farm->info))
		ft_errors("Error: no number of ants");
	if ((farm->num_ants = ft_atoi(farm->info)) < 1)
		ft_errors("Error: no ants given");
	farming(farm);
	free(farm->info);
}

void			rooming(t_farm *farm)
{
	int	len;
	int	status;

	while (get_next_line(0, &farm->info) > 0)
	{
		if (!ft_strchr(farm->info, ' ') && farm->info[0] != '#')
			break ;
		if (!ft_strcmp(farm->info, "##start"))
			status = 1;
		if (!ft_strcmp(farm->info, "##end"))
			status = 2;
		if (farm->info[0] != '#')
		{
			len = ft_strchr(farm->info, ' ') - farm->info;
			build_room(farm, len);
			if (status == 1)
				farm->start_room = ft_strndup(farm->info, len);
			if (status == 2)
				farm->end_room = ft_strndup(farm->info, len);
			status = 0;
		}
		farming(farm);
		free(farm->info);
	}
}

void			linking(t_farm *farm)
{
	char **links;

	if (farm->info)
		first_link(farm);
	while (get_next_line(0, &farm->info) > 0)
	{
		if (!ft_strchr(farm->info, '-') && farm->info[0] != '#')
			break ;
		if (farm->info[0] != '#')
		{
			links = ft_strsplit(farm->info, '-');
			if (ft_strequ(links[0], links[1]))
			{
				ft_strings_del(links);
				ft_errors("Error: rooms link broken");
			}
			put_link(farm, links[0], links[1]);
			put_link(farm, links[1], links[0]);
			ft_strings_del(links);
		}
		farming(farm);
		free(farm->info);
	}
}

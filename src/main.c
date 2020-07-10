/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:37:54 by tngwenya          #+#    #+#             */
/*   Updated: 2018/11/29 11:42:53 by tngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void		initiating(t_farm *farm)
{
	farm->num_ants = 0;
	farm->num_room = 0;
	farm->info = NULL;
	farm->start_room = NULL;
	farm->end_room = NULL;
	farm->rooms = NULL;
	farm->file = NULL;
}

void		print_path(t_path *path, t_farm *farm)
{
	static int fill = 0;
	static int ant = 1;
	
	while(path)
	{
		fill = 0;
		ant = 1;
		while(fill < farm->num_ants)
		{
			ft_putchar('\n');
			ft_putchar('L');
			ft_putnbr(ant++);
			ft_putchar('-');
			ft_putstr(path->name);
			fill++;
		}
		path = path->next;
	}
	ft_putendl("");
}

int			main(void)
{
	t_farm	farm;
	t_path	*path;

	initiating(&farm);
	anting(&farm);
	rooming(&farm);
	linking(&farm);
	proofing(&farm);
	printing(farm.file);
	path = begin(&farm);
	print_path(path, &farm);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:09:15 by tngwenya          #+#    #+#             */
/*   Updated: 2018/12/03 17:58:13 by tngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_info
{
	char			*data;
	struct s_info	*next;
}					t_info;

typedef struct		s_path
{
	int				last;
	char			*name;
	struct s_path	*next;
}					t_path;

typedef struct		s_room
{
	char			*name;
	struct s_room	*next;
	struct s_path	**paths;
	struct s_link	*link;
}					t_room;

typedef struct		s_link
{
	t_room			*room;
	struct s_link	*next;
}					t_link;

typedef struct		s_farm
{
	int				num_ants;
	int				num_room;
	char			*info;
	char			*start_room;
	char			*end_room;
	t_info			*file;
	t_room			*rooms;
}					t_farm;

void				proofing(t_farm *farm);
void				anting(t_farm *farm);
void				rooming(t_farm *farm);
void				linking(t_farm *farm);
void				farming(t_farm *farm);
void				printing(t_info *file);
void				ft_errors(char *msg);
void				build_room(t_farm	*farm, int len);
t_room				*select_room(char *name, t_room *rooms);
void				put_link(t_farm *farm, char *src, char *dest);
t_path				*begin(t_farm *farm);
t_path				*path_search(t_farm *farm, t_room *start);

#endif

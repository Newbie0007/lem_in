/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:23:31 by tngwenya          #+#    #+#             */
/*   Updated: 2018/10/10 19:19:52 by tngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strings_del(char **strings)
{
	int		i;

	i = 0;
	if (!strings || !*strings)
		return ;
	while (strings[i])
	{
		ft_strdel(&strings[i]);
		i++;
	}
	free(strings);
	strings = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_root.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:57:30 by tngwenya          #+#    #+#             */
/*   Updated: 2018/09/03 15:58:16 by tngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int root;

	root = 1;
	while (root * root != nb)
	{
		if (root / 2 > nb)
		{
			break ;
		}
		root++;
	}
	if (root * root == nb)
		return (root);
	return (0);
}

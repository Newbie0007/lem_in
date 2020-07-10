/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmakgato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:02:46 by fmakgato          #+#    #+#             */
/*   Updated: 2018/06/11 09:58:03 by fmakgato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	long sum;
	long x;
	long neg;

	sum = 0;
	neg = 1;
	x = 0;
	while ((str[x] >= 9 && str[x] <= 13) || (str[x] == ' '))
		x++;
	if (str[x] == '-')
	{
		neg = -1;
		x++;
	}
	else if (str[x] == '+')
		x++;
	while (str[x] >= '0' && str[x] <= '9')
	{
		sum = sum * 10 + str[x] - '0';
		x++;
		if (sum <= (-2147483648) || sum >= (+2147483648))
		{
			ft_putstr("ERROR\n");
			return (sum);
		}
	}
	return (sum * neg);
}

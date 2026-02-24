/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:21:42 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/11 19:38:24 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_atol(char *argv_char)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	i = 0;
	while (argv_char[i])
	{
		while (argv_char[i] == ' ' || (argv_char[i] >= 9 && argv_char[i] <= 13)
			|| argv_char[i] == 39)
			i++;
		if (argv_char[i] == '-' || argv_char[i] == '+')
		{
			if (argv_char[i] == '-')
				sign = -1;
			i++;
		}
		while (argv_char[i] >= '0' && argv_char[i] <= '9')
		{
			result = result * 10 + (argv_char[i] - '0');
			i++;
		}
	}
	return (result * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:51:09 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/12 19:04:44 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	check_minmax(char **argv)
{
	int		i;
	long	num;

	i = 0;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	check_dups(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_valid_number(char *str)
{
	int	j;

	j = 0;
	while (str[j] == ' ' || (str[j] >= 9 && str[j] <= 13) || str[j] == 39)
		j++;
	if (str[j] == '-' || str[j] == '+')
		j++;
	if (str[j] == '\0')
		return (0);
	while (str[j])
	{
		if (!(str[j] >= '0' && str[j] <= '9'))
			return (0);
		j++;
	}
	return (1);
}

int	check_num(char **argv)
{
	int	i;
	int	numbers;

	i = 0;
	numbers = 0;
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
			return (0);
		numbers++;
		i++;
	}
	if (numbers == 0 || !check_dups(argv))
		return (0);
	return (1);
}

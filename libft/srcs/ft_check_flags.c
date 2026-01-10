/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 16:59:36 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/10 18:18:34 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	check_flags(int argc, char **argv, t_flags flags)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		if (ft_strcmp(argv[i], "--bench") == 0 && !flags.bench)
			flags.bench = 1;
		else if (ft_strcmp(argv[i], "--simple") == 0 && !flags.simple)
			flags.simple = 1;
		else if (ft_strcmp(argv[i], "--medium") == 0 && !flags.medium)
			flags.medium = 1;
		else if (ft_strcmp(argv[i], "--complex") == 0 && !flags.complex)
			flags.complex = 1;
		else if (ft_strcmp(argv[i], "--adaptive") == 0 && !flags.adaptive)
			flags.complex = 1;
		else
			return (-1);
		i++;
	}
	return (i);
}

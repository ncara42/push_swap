/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 08:47:55 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/05 23:29:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ftp_putnbr(int nb)
{
	long	n;
	int		count;

	count = 0;
	n = nb;
	if (n < 0)
	{
		count += ftp_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ftp_putnbr(n / 10);
	count += ftp_putchar((n % 10) + '0');
	return (count);
}

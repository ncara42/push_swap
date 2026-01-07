/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_putnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 08:47:55 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/07 17:30:26 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ftp_float(float nb)
{
	int		fnum;
	int		fdec;
	int		count;

	count = 0;
	if (nb < 0)
	{
		count += ftp_putchar('-');
		nb = -nb;
	}
	fnum = (int)nb;
	ftp_putnbr(fnum);
	ftp_putchar('.');
	fdec = (int)((nb - fnum) * 100 + 0.5);
	if (fdec < 10)
		ftp_putchar('0');
	ftp_putnbr(fdec);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 08:48:35 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/05 23:29:14 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ftp_puthex(uintptr_t n, unsigned int upper)
{
	char	*hex;
	int		count;

	count = 0;
	if (upper)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		count += ftp_puthex(n / 16, upper);
	count += ftp_putchar(hex[n % 16]);
	return (count);
}

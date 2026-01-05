/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 08:49:46 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/05 23:29:29 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ftp_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ftp_putunsigned(n / 10);
	count += ftp_putchar((n % 10) + '0');
	return (count);
}

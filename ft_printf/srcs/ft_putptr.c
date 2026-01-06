/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 08:49:20 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/06 01:19:44 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ftp_putptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (ftp_putstr("(nil)"));
	count = 0;
	count += ftp_putstr("0x");
	count += ftp_puthex((uintptr_t)ptr, 1);
	return (count);
}

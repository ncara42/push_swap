/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 06:36:21 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/05 23:29:06 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ftp_conversion(const char *format, int i, va_list args, int count)
{
	if (format[i] == 'c')
		count += ftp_putchar(va_arg(args, int));
	else if (format[i] == 'd' || format[i] == 'i')
		count += ftp_putnbr(va_arg(args, int));
	else if (format[i] == 's')
		count += ftp_putstr(va_arg(args, char *));
	else if (format[i] == 'p')
		count += ftp_putptr(va_arg(args, void *));
	else if (format[i] == 'x')
		count += ftp_puthex(va_arg(args, unsigned int), 1);
	else if (format[i] == 'X')
		count += ftp_puthex(va_arg(args, unsigned int), 0);
	else if (format[i] == 'u')
		count += ftp_putunsigned(va_arg(args, unsigned int));
	else if (format[i] == '%')
		count += ftp_putchar('%');
	return (count);
}

int	ftp_print_loop(int count, int i, va_list args, const char *format)
{
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count = ftp_conversion(format, i, args, count);
		}
		else
			count += ftp_putchar(format[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ftp_print_loop(0, 0, args, format);
	va_end(args);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 07:16:05 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/10 04:07:06 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ftp_putchar(char c);
int	ftp_putstr(char *s);
int	ftp_putnbr(int n);
int	ftp_float(float nb);
int	ftp_puthex(uintptr_t n, unsigned int upper);
int	ftp_putptr(void *ptr);
int	ftp_putunsigned(unsigned int n);
int	ftp_print_loop(int count, int i, va_list args, const char *format);
int	ftp_conversion(const char *format, int i, va_list *args, int count);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaga <thaga@student.42tokyo.jp>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-12 03:57:55 by thaga             #+#    #+#             */
/*   Updated: 2026-10-12 03:57:55 by thaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	print_assign(char base, va_list *ap)
{
	if (base == 'c')
		return (print_char(va_arg(*ap, int)));
	else if (base == 's')
		return (print_str(va_arg(*ap, char *)));
	else if (base == 'p')
		return (print_pointer(va_arg(*ap, void *)));
	else if (base == 'd' || base == 'i')
		return (print_decimal(va_arg(*ap, int)));
	else if (base == 'u')
		return (print_unsigned_int(va_arg(*ap, unsigned int)));
	else if (base == 'x')
		return (print_hex(va_arg(*ap, unsigned int)));
	else if (base == 'X')
		return (print_hex_upper(va_arg(*ap, unsigned int)));
	else if (base == '%')
		return (write(1, "%", 1));
	return (write(1, &(base), 1));
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	int			tmp;
	const char	*base;

	va_start(ap, format);
	base = format;
	count = 0;
	while (*base)
	{
		if (*base == '%')
		{
			base++;
			if (*base == '\0')
				break ;
			tmp = print_assign(*base, &ap);
		}
		else
			tmp = print_char(*base);
		if (tmp < 0)
			return (va_end(ap), -1);
		count += tmp;
		base++;
	}
	return (va_end(ap), count);
}

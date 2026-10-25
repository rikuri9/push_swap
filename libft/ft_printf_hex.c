/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaga <thaga@student.42tokyo.jp>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-13 05:26:06 by thaga             #+#    #+#             */
/*   Updated: 2026-10-13 05:26:06 by thaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

static size_t	get_hex_size(unsigned long num)
{
	size_t	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}

static int	convert_hex(unsigned long num, char *digit)
{
	char	hex[16];
	size_t	size;
	size_t	i;

	size = get_hex_size(num);
	if (num == 0)
		hex[0] = '0';
	i = size;
	while (num != 0)
	{
		i--;
		hex[i] = digit[num % 16];
		num /= 16;
	}
	return (write(1, hex, size));
}

int	print_hex(unsigned int num)
{
	return (convert_hex(num, "0123456789abcdef"));
}

int	print_hex_upper(unsigned int num)
{
	return (convert_hex(num, "0123456789ABCDEF"));
}

int	print_pointer(void *p)
{
	unsigned long	pn;
	int				ret1;
	int				ret2;

	if (p == NULL)
		return (write(1, "(nil)", ft_strlen("(nil)")));
	pn = (unsigned long) p;
	ret1 = write(1, "0x", ft_strlen("0x"));
	if (ret1 < 0)
		return (-1);
	ret2 = convert_hex(pn, "0123456789abcdef");
	if (ret2 < 0)
		return (-1);
	return (ret1 + ret2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaga <thaga@student.42tokyo.jp>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-13 04:36:09 by thaga             #+#    #+#             */
/*   Updated: 2026-10-13 04:36:09 by thaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int	print_decimal(int num)
{
	int		len;
	char	*str;

	str = ft_itoa(num);
	if (!str)
		return (-1);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

static int	get_digit_len(unsigned int un)
{
	int	count;

	count = 0;
	if (un == 0)
		return (1);
	while (un != 0)
	{
		un /= 10;
		count++;
	}
	return (count);
}

int	print_unsigned_int(unsigned int num)
{
	int		idx;
	int		len;
	char	str[10];

	len = get_digit_len(num);
	idx = len;
	if (num == 0)
		str[0] = '0';
	while (num != 0)
	{
		idx--;
		str[idx] = (num % 10) + '0';
		num /= 10;
	}
	return (write(1, str, len));
}

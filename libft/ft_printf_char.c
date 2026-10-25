/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaga <thaga@student.42tokyo.jp>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-13 04:14:22 by thaga             #+#    #+#             */
/*   Updated: 2026-10-13 04:14:22 by thaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

int	print_char(int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	return (write(1, &ch, 1));
}

int	print_str(char *s)
{
	char	*str;

	str = s;
	if (str == NULL)
		str = "(null)";
	return (write(1, str, ft_strlen(str)));
}

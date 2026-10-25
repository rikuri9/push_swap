/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaga <thaga@student.42tokyo.jp>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-08 06:57:35 by thaga             #+#    #+#             */
/*   Updated: 2026-10-08 06:57:35 by thaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_space(int n)
{
	if ((n >= 9 && n <= 13) || n == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	i = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return ((int)(sign * result));
}

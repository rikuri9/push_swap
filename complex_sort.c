/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:14:24 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/27 18:01:12 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	max_bits(int n)
{
	int bits;

	bits = 0;
	while (((n - 1) >> bits) != 0)
		bits++;
	return (bits);
}

void	complex_sort(t_data *data)
{
	int	n;
	int	bits;
	int	i;
	int	j;

	n = data->a.size;
	bits = max_bits(n);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < n)
		{
			if (((data->a.top->index >> i) & 1) == 0)
				op_exe(data, &pb, 1);
			else
				op_exe(data, &ra, 1);
			j++;
		}
		op_exe(data, &pa, data->b.size);
		i++;
	}
}
